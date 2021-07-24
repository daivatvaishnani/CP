#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ndigits(ll b) {
    ll nd = 0;
    while(b > 0) {
        b /= 10;
        ++nd;
    }
    return nd;
}

ll conc(ll a, ll b) {
    return a * pow(10, ndigits(b)) + b;
}

ll solve_slow(ll a, ll b) {
    ll ans = 0;
    for(ll i = 1; i <= a; ++i) {
        for(ll j = 1; j <= b; ++j) {
            if(i*j + i + j == conc(i, j)) {
                // cout << i << " " << j << "\n";
                ans++;
            }
        }
    }
    return ans;
}

ll solve(ll a, ll b) {
    // find np a,b such that a <= a and b <= b
    // => a * b + a + b = conc(a, b)
    // => (b + 1) * a + b = 10^(ndigits(b)) * a + b
    // => b + 1 = 10^(ndigits(b))
    // => b = 9, 99, 999, 9999, ...
    // cb = ndigits(b)
    // np = cb * A
    ll db = ndigits(b);
    ll ld = pow(10, db) - 1;
    db = b >= ld ? db : db-1;
    ll np = db * a;
    return np;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
        // cout << solve_slow(a, b) << "--\n";
    }
    return 0;
}