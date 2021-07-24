#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,ans=0;
	long double r,d,x,y,ri;
	cin >> r >> d >> n;
	while(n--) {
		cin >> x >> y >> ri;
		if(x*x + y*y >= pow(r-d+ri,2) && x*x + y*y <= pow(r-ri,2)) ++ans; 
	}
	cout << ans << "\n";
	return 0;
}