#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;
bool q[5], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> t;
	while(t--) {
		ans = 1;
		for(int i = 0; i < 5; ++i) {
			q[i] = 0; 
		}
		cin >> n;
		while(n--) {
			cin >> s;
			if(s == "cakewalk") ++q[0];
			if(s == "simple") ++q[1];
			if(s == "easy") ++q[2];
			if(s == "easy-medium" || s == "medium") ++q[3];
			if(s == "medium-hard" || s == "hard") ++q[4];
		}
		for(int i = 0; i < 5; ++i) {
			if(q[i] == 0) {
				ans = 0;
				break;
			}
		}
		if(ans == 1) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}