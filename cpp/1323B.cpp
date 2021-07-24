/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<ll, ll> > findcs(vector<ll> &a) {
    unordered_map<ll, ll> m;
    vector<pair<ll, ll> > acs;
    ll cs = 0;
    for(ll i = 0; i <= a.size(); ++i) {
        if(i == a.size() || a[i] == 0) {
            if(cs > 0) {
                m[cs]++;
                cs = 0;
            }
        } else {
            cs++;
        }
    }
    for(auto p : m) {
        acs.push_back({p.first, p.second});
    }
    return acs;
}

vector<pair<ll, ll> > findsizes(ll k) {
    vector<pair<ll, ll> > sizes;
    for(ll i = 1; i*i <= k; ++i) {
        if(k % i == 0) {
            sizes.push_back({i, k/i});
        }
    }
    return sizes;
}

ll solve(ll n, ll m, ll k, vector<ll> &a, vector<ll> &b) {
    ll ans = 0;
    vector<pair<ll, ll> > acs = findcs(a);
    vector<pair<ll, ll> > bcs = findcs(b);
    ll dimx, dimy, cnt;
    vector<pair<ll, ll> > sizes = findsizes(k);
    for(ll i = 0; i < acs.size(); ++i) {
        for(ll j = 0; j < bcs.size(); ++j) {
            dimx = acs[i].first;
            dimy = bcs[j].first;
            cnt = acs[i].second * bcs[j].second;
            if(dimx * dimy == k) {
                ans += cnt;

            } else if(dimx * dimy > k) {
                ll subs = 0;
                for(auto s : sizes) {
                    subs += cnt * max(0LL, (dimx - s.first + 1) * (dimy - s.second + 1));
                    if(s.first != s.second) {
                        subs += cnt * max(0LL, (dimx - s.second + 1) * (dimy - s.first + 1));    
                    }
                }
                ans += subs;
            }
        }
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < m; ++i) cin >> b[i];
    cout << solve(n, m, k, a, b) << "\n";
    return 0;
}