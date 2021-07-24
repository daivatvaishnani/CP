#include <bits/stdc++.h>

using namespace std;

vector<string> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int t;
	int n, c0, c1;
	bool one = 1;
	string s;
	cin >> t;
	while(t--) {
		S.clear();
		one = 1;
		c0 = 0;
		c1 = 0;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> s;
			if(one) {
				S.push_back(s);
				one = 0;
				c0 = 1;
				continue;
			}
			if(S.size() == 2) {
				if(S[0] == s) ++c0;
				else ++c1;
				continue;
			}
			if(S[0] == s) ++c0;
			else {
				S.push_back(s);
				c1 = 1;
			} 
		}
		if(c0 > c1) {
			cout << S[0] << "\n";
			continue;
		}
		if(c1 > c0) {
			cout << S[1] << "\n";
			continue; 
		}
		cout << "Draw\n";
	}	
	return 0;
}