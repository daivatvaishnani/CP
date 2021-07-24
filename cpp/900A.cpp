#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n, x, y, c1 = 0, c2 = 0;
	cin >> n;
	while(n--) {
		cin >> x >> y;
		if(x < 0) ++c1;
		else ++c2;
	}
	if(c1 <=  1 || c2 <= 1) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	return 0;
}