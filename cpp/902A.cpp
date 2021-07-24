#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n, m, a, b;
	cin >> n >> m;
	int pos = 0;
	bool ok = 1;
	while(n--) {
		cin >> a >> b;
		if(a > pos) {
			ok = 0;
			break;
		}
		pos = max(pos, b);
	}
	if(ok) {
		if(pos >= m) {
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