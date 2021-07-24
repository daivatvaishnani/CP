/**
* Problem Link: https://www.codechef.com/LTIME88A/problems/ROOTTREE
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void test_case() {
	ll n;
	cin >> n;
	vector<ll> par(n+1, -1);
	vector<ll> reach(n+1, 0);
	for(ll i = 0; i < n-1; ++i) {
		ll u, v;
		cin >> u >> v;
		if(par[v] == -1) {
			while(par[u] != -1) {
				u = par[u];
			}
			par[v] = u;
			reach[u] += reach[v] + 1;
			if(reach[v] > 0) {
				reach[v] = 0;
			}	
		}
	}
	ll reached = 0, numzero = 0;
	for(ll i = 1; i <= n; ++i) {
		if(reach[i] == 0) {
			numzero++;
		}
		reached += reach[i];
	}
	ll ans = n - numzero - 1;
	if(numzero > reached) {
		ans += numzero - reached;
	}
	cout << ans << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        test_case();
    }
    return 0;
}