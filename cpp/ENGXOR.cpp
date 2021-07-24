/**
* Problem Link: https://www.codechef.com/MARCH20B/problems/ENGXOR
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void prll(vector<ll> &a) {
    for(ll i : a) cout << i << " ";
    cout << "\n";
}

ll find_parity(ll a) {
    ll parity = 0;
    for(ll i = 0; i < 64; ++i) {
        if((1LL << i) & a) {
            parity = (parity + 1) & 1;
        }
    }
    return parity;
}

string solve(ll n, ll q, vector<ll> &a, vector<ll> &p) {
    string ans = "";
    vector<ll> cnt(2);
    for(ll i = 0; i < q; ++i) {
        cnt[0] = 0, cnt[1] = 0;
        for(ll j = 0; j < n; ++j) {
            cnt[(ll)find_parity(a[j] ^ p[i])]++;
        }
        ans += to_string(cnt[0]) + " " + to_string(cnt[1]) + "\n";
    }
    return ans;
}

string solve_fast(ll n, ll q, vector<ll> &a, vector<ll> &p) {
    string ans = "", app;
    vector<ll> cnt(2);
    cnt[0] = 0, cnt[1] = 0;
    for(ll i = 0; i < n; ++i) {
        cnt[find_parity(a[i])]++;
    }
    for(ll i = 0; i < q; ++i) {
        if(find_parity(p[i])) {
            app = to_string(cnt[1]) + " " + to_string(cnt[0]) + "\n";
        } else {
            app = to_string(cnt[0]) + " " + to_string(cnt[1]) + "\n";
        }
        ans += app;
    }
    return ans;
}

int main() {
    // freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        ll n, q;
        cin >> n >> q;
        vector<ll> a(n), p(q);
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(ll i = 0; i < q; ++i) {
            cin >> p[i];
        }
        // string ans1 = solve(n, q, a, p);
        string ans2 = solve_fast(n, q, a, p);
        // if(ans1 == ans2) {
        //     cout << "Correct!\n";
        // }
        cout << ans2 << "\n";
    }
    return 0;
}