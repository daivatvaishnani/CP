#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n, p1 = 1, p2 = 2, s = 3, w = 0;
	bool ok = 1;
	cin >> n;
	while(n--) {
		cin >> w;
		if(w == p1) {
			swap(s, p2);
		}
		else if(w == p2) {
			swap(s, p1);
		}
		else {
			ok = 0;
		}
	}
	if(ok) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}