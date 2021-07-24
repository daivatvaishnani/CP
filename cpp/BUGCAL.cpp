#include <bits/stdc++.h>

using namespace std;

string s[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		int a = 0, b = 0, maxn = 0, diff = 0;
		for(int i = 0; i < 4; ++i) {
			s[i].clear();
		}
		cin >> s[0] >> s[1];
		if(s[1].size() != s[0].size()) {
			maxn = (s[1].size() > s[0].size()) ? 0 : 1;
			diff = max(s[1].size(), s[0].size()) - min(s[1].size(), s[0].size());
			while(diff--) {
				s[maxn] = '0' + s[maxn];
			}
		}
		for(int i = 0; i < s[1].size(); ++i) {
			maxn = (s[1][i] - '0') + (s[0][i] - '0');
			s[2] = to_string(maxn);
			s[3] += s[2][s[2].size() - 1];
		}
		if(s[1].size() > 1) {
			for(int i = 0; i < s[3].size(); ++i) {
				diff = s[3][i] - '0';
				if(diff > 0) {
					maxn = i;
					break;
				}
			}
			for(int i = maxn; i < s[3].size(); ++i) {
				cout << s[3][i]; 
			}
			cout << "\n";
		}
		else {
			cout << s[3] << "\n";
		}
	}
	return 0;
}