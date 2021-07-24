/**
* Problem Link: https://www.codechef.com/LTIME83B/problems/MEXUM
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;
const ll maxn = 1e5 + 5;

ll pow2[maxn];

ll add(ll a, ll b) {
    return (a % mod + b % mod) % mod;
}

ll sub(ll a, ll b) {
    return (mod + a % mod - b % mod) % mod;
}

ll mul(ll a, ll b) {
    return (a % mod * b % mod) % mod;
}

void test_case(ll case_no) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];   
    }
    sort(a.begin(), a.end());
    vector<pair<ll,ll>> p;
    ll l = -13, lc = 0;
    for(ll i = 0; i < n; ++i) {
        if(a[i] != l) {
            if(l >= 1 && lc > 0) {
                p.push_back({l, lc});
            }
            l = a[i];
            lc = 1;
        } else {
            lc++;
        }
    }
    if(l >= 1 && lc > 0) {
        p.push_back({l, lc});
    }
    ll sz = p.size();
    vector<ll> cnt(sz+1);
    cnt[0] = 1LL;
    ll ans = 0;
    ll cm = 1, psm = 0, ps = 1, sm, ss;
    for(ll i = 0; i < sz; ++i) {
        if(cm < p[i].first) {
            sm = mul(mul(ps, pow2[n-psm]), cm);
            ans = add(ans, sm);
            break;
        } else if(cm == p[i].first) {
            psm += p[i].second;
            sm = mul(mul(ps, pow2[n-psm]), cm);
            ps = mul(ps, pow2[p[i].second]-1);
            ans = add(ans, sm);
            cm = p[i].first+1;
        }
    }
    if(cm == p[sz-1].first+1) {
        sm = mul(ps, cm);
        ans = add(ans, sm);
    }
    cout << ans << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    pow2[0] = 1;
    for(ll i = 1; i < maxn; ++i) {
        pow2[i] = mul(pow2[i-1], 2);
    }
    for(ll i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}