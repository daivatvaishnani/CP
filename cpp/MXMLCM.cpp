/**
* Problem Link: https://www.codechef.com/LTIME82B/problems/MXMLCM
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 10005;

ll _gcd(ll a, ll b) { 
    if (a == 0) 
        return b; 
    return _gcd(b % a, a); 
} 

ll _lcm(ll a, ll b) {
    return ((a * b) / _gcd(a, b));
}

ll solve_slow(ll n, ll m, vector<ll> &a) {
    ll lcm = 1;
    for(ll i : a) {
        lcm = _lcm(lcm, i);
    }
    cout << lcm << "\n";
    ll maxlcm = lcm, tlcm, ans = 1;
    for(ll i = 1; i <= m; ++i) {
        tlcm = _lcm(lcm, i);
        if(tlcm > maxlcm) {
            ans = i;
        }
    }
    return ans;
    return 1;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    vector<vector<ll> > max_lcms(maxn, vector<ll> (maxn));
    for(int i = 1; i <= maxn; ++i) {
        int tlcm = 1, maxlcm = i;
        for(int j = 1; j <= maxn; ++i) {
            tlcm = _lcm(j, i);
            if(tlcm > )
        }
    }
    while(t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve_slow(n, m, a) << "\n";
    }
    return 0;
}