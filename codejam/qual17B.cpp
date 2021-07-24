#include <bits/stdc++.h>

using namespace std;

int t, start, szs;
string s;
bool nd, d, one;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> t;
	for(int cases = 1; cases <= t; ++cases) {
		cin >> s;
		szs = s.size();
		d = false, nd = false, one = true;
		if(szs > 1) {
			while(!d) {
				one = true;
				for(int i = 0; i < szs - 1; ++i) {
					if(s[i] > s[i + 1]) {
						if(one) {
							s[i] = ((s[i] - '0') - 1) + '0';
							one = false;
						}
						s[i + 1] = '9';
					}
				}
				for(int i = 0; i < szs - 1; ++i) {
					if(s[i] > s[i + 1]) {
						nd = true;
					}
				}
				if(!nd) {
					d = true;
				}
				nd = false;
			}
		}
		for(int i = 0; i < szs; ++i) {
			if(s[i] != '0') {
				start = i;
				break;
			} 
		}
		cout << "CASE #" << cases << ": " << s.substr(start, szs - start);
		if(cases != t) {
			cout << "\n";
		}
	}
	return 0;
}
