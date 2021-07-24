#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll n, k;

ll solve(ll empty) {
	ll ans = 0;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> t;
	for(int cases = 1; cases <= n; ++cases) {
		cin >> n;
		// if(n & 1) {
		// 	0......0......0
		// }
		// else {
		// 	0.00.0.0.0
		// }
		cout << "CASE #" << cases << ": " << solve(n);
		if(cases != n) {
			cout << "\n";
		}
	}
	return 0;
}
