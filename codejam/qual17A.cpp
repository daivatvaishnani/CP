#include <bits/stdc++.h>

using namespace std;

int t, k, szs, ans;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> t;
	for(int cases = 0; cases < t; ++cases) {
		ans = 0;
		cin >> s >> k;
		szs = s.size();
		for(int i = 0; i + k - 1 < szs; ++i) {
			if(s[i] == '-') {
				for(int j = 0; j < k; ++j) {
					s[i + j] = s[i + j] == '-' ? '+' : '-'; 
				}
				++ans;
			}
		}
		for(int i = 0; i < szs; ++i) {
			if(s[i] == '-') {
				ans = -1;
			}
		}
		cout << "CASE #" << cases + 1 << ": ";
		ans == -1 ? cout << "IMPOSSIBLE" : cout << ans;
		if(cases != t - 1) {
			cout << "\n";
		}
	}
	return 0;
}