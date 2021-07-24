#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll m,b,ans,tmp;
ll X,Y;
int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> m >> b;
	ans = 0;
	for(int i=b; i>=0; --i) {
		Y = i;
		X = (b-Y)*m;
		tmp = (Y*(Y + 1)*(X + 1) + X*(Y + 1)*(X + 1))/2;
		ans = max(ans , tmp);
	}
	cout << ans << "\n";
}