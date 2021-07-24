#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n;
	cin >> n;
	int c1 = 0, c2 = 0;
	while(n--) {
		int a;
		cin >> a;
		if(a == 1) ++c1;
		else ++c2;
	}
	int teams = 0;
	teams = min(c1, c2);
	c1 = c1 - teams;
	if(c1 > 0) teams += c1 / 3;
	cout << teams<< "\n";
	return 0;
}