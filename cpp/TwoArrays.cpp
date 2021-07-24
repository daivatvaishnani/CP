#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<ll> vi;
typedef vector<pair<vector<ll>, vector<ll> > > vpvi;

const ll mod = 1e9 + 7;

ll add(ll a, ll b) {
    return (a % mod + b % mod) % mod;
}

ll mul(ll a, ll b) {
    return (a % mod * b % mod) % mod;
}

ll n, m;
ll compute = 0;
ll dp[30][1001];

ll go(ll id, ll ld) {
    if(dp[id][ld] == -1) {
        // compute
        ll pairs = 0;
        if(id > 2*m) {
            pairs = 1;
        } else {
            for(int i = ld; i <= n; ++i) {
                pairs = add(pairs, go(id+1, i));
            }
        }
        dp[id][ld] = pairs;
    }    
    return dp[id][ld];
}

ll solve(ll n, ll m) {
    ll pairs = 0;
    memset(dp, -1, sizeof(dp));
    compute = 0;
    for(ll i = 1; i <= n; ++i) {
        pairs = add(pairs, go(2, i));
    }
    return pairs;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cout << solve(n, m) << "\n";
    return 0;
}