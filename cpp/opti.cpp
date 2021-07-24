#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll m,b,ans;
ll A,B,C;
ll X,Y;
int main() {
	ios_base::sync_with_stdio(false);
	freopen("in","r",stdin); freopen("out","w",stdout);
	cin >> m >> b;
	A = 3*(m*m - m);
	B = 2*(m*m + m*b + 1 - 2*m - 2*m*m*b);
	C = m*m*b*b* - 2*m*m*b + 2*m*b - m + 1;
	Y = (-B + sqrt(B*B - 4*A*C))/(2*A);
	X = (b - Y)*m;
	ans = (X + 1)*(Y + 1)*(X + Y); 
	cout << ans << "\n";
}