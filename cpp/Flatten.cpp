// https://atcoder.jp/contests/abc152/tasks/abc152_e
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9+7;
const ll N = 1e4+7;

ll gcd(ll a, ll b){ 
    if (a == 0) {
        return b;  
    }
    return gcd(b % a, a);  
} 
   
ll lcm(ll a, ll b)  {  
    return (a * b) / gcd(a, b);  
} 

ll add(ll a, ll b) {
    return (a % mod + b % mod) % mod;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll lcmij[n][n];
    memset(lcmij, -1, sizeof(lcmij));
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            lcmij[i][j] = lcm(a[i], a[j]);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << lcmij[i][j] << " ";
        }
        cout << "\n";
    }
    ll lcmc;
    for(int i = 0; i < n; ++i) {
        lcmc = 1;
        for(int j = 0; j < n; ++j) {
            lcmc = lcm(lcmc, lcmij[i][j] / a[i]);
        }
        b[i] = lcmc / a[i];
        ans = add(ans, b[i]);
    }
    cout << ans << "\n";
    return 0;
}