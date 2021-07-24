#include <bits/stdc++.h>

using namespace std;

int n, nsf, nfs;
string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> n;
	cin >> s;
	t = t + s[0];
	for(int i = 1; i < s.size(); ++i) {
		if(s[i] != s[i-1]) {
			t = t + s[i];
		}
	}
	for(int i = 1; i < t.size(); ++i) {
		if(t[i] == 'F') ++nsf;
		else ++nfs;
	}
	if(nsf > nfs) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}