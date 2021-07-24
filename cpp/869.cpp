#include <bits/stdc++.h>

using namespace std;

long long a[2000], b[2000];
unordered_set<long long> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	long long n;
	cin >> n;
	for(long long i = 0; i < n; ++i) {
		cin >> a[i];
		s.insert(a[i]);
	}
	for(long long i = 0; i < n; ++i) {
		cin >> b[i];
		s.insert(b[i]);
	}
	long long cnt = 0;
	for(long long i = 0; i < n; ++i) {
		for(long long j = 0; j < n; ++j) {
			if(s.find(a[i] ^ b[j]) != s.end()) {
				++cnt;
			}
		}	
	}
	if(cnt & 1) {
		cout << "Koyomi\n";
	}
	else cout << "Karen\n";
	return 0;
}