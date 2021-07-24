#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline void tcase() {
    cout << "==========================\n";
}

bool solve(ll n, ll m, vector<ll> &t, vector<ll> &l, vector<ll> &h) {
    ll g;
    vector<ll> lr(n, -1), hr(n, -1);
    hr[n-1] = h[n-1], lr[n-1] = l[n-1];
    // cout << "rec " << lr[n-1] << " " << hr[n-1] << "\n";
    for(ll i = n-1; i >= 1; --i) {
        g = t[i] - t[i-1];
        // get reachables
        lr[i-1] = lr[i] - g, hr[i-1] = hr[i] + g;
        if((h[i-1] <= lr[i] || l[i-1] >= hr[i]) && !(h[i-1] <= lr[i] && l[i-1] >= hr[i])) {
            if(h[i-1] <= lr[i]) {
                hr[i-1] = max(h[i-1], lr[i-1]);
            } else {
                lr[i-1] = min(l[i-1], hr[i-1]);
            }
        } else {
            hr[i-1] = min(h[i-1], hr[i-1]);
            lr[i-1] = max(l[i-1], lr[i-1]);
        }
        // cout << "rec " << lr[i-1] << " " << hr[i-1] << "\n";
        if(h[i-1] < lr[i-1] || l[i-1] > hr[i-1]) {
            return 0;
        }
    }
    ll hr_o = m + t[0], lr_o = m - t[0];
    // cout << lr_o << " " << hr_o << " ?\n";
    if(hr_o < lr[0] || lr_o > hr[0]) {
        return 0;
    }
    return 1;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll q;
    cin >> q;
    while(q--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> t(n), l(n), h(n);
        for(ll i = 0; i < n; ++i) {
            cin >> t[i] >> l[i] >> h[i];
        }
        // tcase();
        bool possible = solve(n, m, t, l, h);
        if(possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        // tcase();
    }
    return 0;
}