/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll add(ll a, ll b, ll p) {
    return ((a % p) + (b % p)) % p;
}

ll mul(ll a, ll b, ll p) {
    return ((a % p) * (b % p)) % p;
}

ll power(ll x, ll y, ll p) { 
    ll res = 1;
    x = x % p;
    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 
  
ll modInverse(ll n, ll p) { 
    return power(n, p-2, p); 
} 

ll nCrModPFermat(ll n, ll r, ll p, vector<ll> &fact) { 
    if (r == 0) {
        return 1; 
    }  
    return (fact[n]* modInverse(fact[r], p) % p * 
            modInverse(fact[n-r], p) % p) % p; 
} 

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> fact(n+1); 
    fact[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fact[i] = fact[i-1]*i%mod; 
    ll num = 0, more;
    for(ll i = 1; i <= m; ++i) {
        more = 
    }
    return 0;
}