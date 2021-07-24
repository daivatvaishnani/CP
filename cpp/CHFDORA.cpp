#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<vector<ll> > vvl;
typedef vector<ll> vl;

void prll_arr(vvl &arr) {
    for(vl &l: arr) {
        for(ll i : l) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

void prll_sep() {
    cout << "---------------\n";
}

bool valid(vvl &arr, ll i, ll j, ll k, ll n, ll m) {
    bool valid = 0;
    if(i-k >= 1 && i+k <= n && j-k >= 1 && j+k <= m) {
        valid = (arr[i-k][j] == arr[i+k][j] && arr[i][j-k] == arr[i][j+k]);
    }
    return valid;
}

ll solve(vvl &arr, ll n, ll m) {
    ll ans = 0;
    // find palindromes in the row..
    // 0 2 1 2 1
    // 0 0 1 1 0

    // 0 2 0 1 0 2 0 
    // 0 1 0 3 0 1 0
    
    return ans;
}

ll solve_slow(vvl &arr, ll n, ll m) {
    ll ans = 0;
    prll_arr(arr);
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            ll k = 0;
            ll valids = 0;
            while(valid(arr, i, j, k, n, m)) {
                k++;
                valids++;
            }
            if(valids > 1) {
                cout << i << ", " << j << " : " << valids << "\n";
            }
            ans += valids;
        }
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        vvl arr(n+2, vl(m+2));
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= m; ++j) {
                cin >> arr[i][j];
            }
        }
        cout << solve_slow(arr, n, m) << "\n";
        cout << "+-<<===========================>>-+\n";
        cout << solve(arr, n, m) << "\n";
    }
    return 0;
}
