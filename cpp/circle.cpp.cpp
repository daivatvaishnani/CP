#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long double l,r,x,y,k;
	cin >> l >> r >> x >> y >> k;
	if(k >= l/y && k <= r/x) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}