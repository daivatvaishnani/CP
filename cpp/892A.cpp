#include <bits/stdc++.h>

using namespace std;

vector<int> b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n, val;
	cin >> n;
	long long rem = 0;
	for(int i = 0; i < n; ++i) {
		cin >> val;
		rem += val;
	}
	for(int i = 0; i < n; ++i) {
		cin >> val;
		b.push_back(val);
	}
	sort(b.begin(), b.end());
	if(b.size() >= 2) {
		int bs = b.size();
		if(b[bs-2] + b[bs-1] >= rem) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	else {
		cout << "NO\n";
	}
	return 0;
}