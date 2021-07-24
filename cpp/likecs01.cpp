#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	int t,szs, flag=0;
	string s,str;
	cin >> t;
	unordered_set <string> S;
	S.clear();
	while(t--) {
		S.clear();
		flag = 0;
		cin >> s;
		szs = s.size();
		for(int i=0; i<szs; ++i) {
			for(int j=0; i+j<szs; ++j) {
				str = s.substr(i, j+1);
				if(S.find(str) == S.end()) {
					S.insert(str);
				}
				else {
					flag = 1;
					break;
				}
			}
			if(flag == 1) {
				break;
			}
		}
		if(flag == 1) {
			cout << "yes\n";
		}
		else cout << "no\n";
	}
	return 0;
}