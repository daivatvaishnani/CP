#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

bool present[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	for(int i = 0; i < N; ++i) {
		present[i] = 0;
	}
	string s;
	cin >> s;
	long long ans = 0;
	int szs = s.size(), num;
	for(int i=0; i < szs; ++i) {
		for(int j = 0; j < 5 && i+j < szs; ++j) {
			num = stoi( s.substr(i, j+1));
			if(present[num] == 0) {
				++ans;
				present[num] = 1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}