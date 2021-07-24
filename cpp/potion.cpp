#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long double l,r,x,y,k;
	cin >> l >> r >> x >> y >> k;
	for(long double i=x; i<=y; ++i) {
		if(k*i >= l && k*i <= r) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}