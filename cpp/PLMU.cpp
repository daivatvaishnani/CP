#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	freopen("in", "r", stdin); freopen("out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while(t--) {
		ll n, a, n0 = 0, n2 = 0;
		cin >> n;
		while(n--) {
			cin >> a;
			if(a == 0) n0++;
			if(a == 2) n2++;
		}
		ll ans = (n0 * (n0 - 1))/2;
		ans += (n2 * (n2 - 1))/2;
		cout << ans << "\n";
	}
	return 0;
}