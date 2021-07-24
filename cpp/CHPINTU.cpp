/**
* Problem Link: https://www.codechef.com/MARCH20B/problems/CHPINTU
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, t, mns;
    cin >> t;
    vector<ll> p, f, sum, nb;
    while(t--) {
        cin >> n >> m;
        p.clear(), p.resize(n);
        f.clear(), f.resize(n);
        sum.clear(), sum.resize(m + 1, 0);
        nb.clear(), nb.resize(m + 1, 0);
        for(ll i = 0; i < n; ++i) {
            cin >> f[i];
        }
        for(ll i = 0; i < n; ++i) {
            cin >> p[i];
        }
        for(ll i = 0; i < n; ++i) {
            sum[f[i]] += p[i];
            nb[f[i]]++;
        }
        mns = LLONG_MAX;
        for(ll i = 1; i <= m; ++i) {
            if(nb[i] > 0) {
                mns = min(mns, sum[i]);
            }
        }
        cout << mns << "\n";
    }
    
    return 0;
}