/**
* Problem Link: https://www.codechef.com/APRIL20B/problems/CARSELL
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll add(ll a, ll b) {
    return (a % mod + b % mod) % mod;
}

ll sub(ll a, ll b) {
    return (mod + a % mod - b % mod) % mod;
}

ll solve(vector<ll> &p, ll n) {
    sort(p.rbegin(), p.rend());
    ll dep = 0, ans = 0, pr;
    for(ll i = 0; i < n; ++i) {
        if(dep >= p[i]) {
            pr = 0;
        } else {
            pr = sub(p[i], dep);
        }
        dep = add(dep, 1);
        ans = add(ans, pr);
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> p(n);
        for(ll i = 0; i < n; ++i) {
            cin >> p[i];
        }
        cout << solve(p, n) << "\n";
    }
    return 0;
}