#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("in","r",stdin);
	int t,n,v,vv;
	long double tt,ttt;
	cin >> t;
	while(t--) {
		cin >> n >> vv >> v;
		tt = 2*n/(v+0.0);
		ttt = sqrt(2)*n/(vv+0.0);
		ttt<tt ? cout << "Stairs\n" : cout << "Elevator\n";
	}
}	