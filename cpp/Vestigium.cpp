/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(vector<vector<ll> > &a, ll n, ll t) {
    ll trace = 0;
    for(ll i = 0; i < n; ++i) {
        trace += a[i][i];
    }
    ll duprows = 0, dupcols = 0;
    unordered_set<ll> s;
    for(ll row = 0; row < n; ++row) {
        s.clear();
        for(ll col = 0; col < n; ++col) {
            if(s.find(a[row][col]) == s.end()) {
                s.insert(a[row][col]);
            } else {
                duprows++;
                break;
            }
        }
    }
    for(ll col = 0; col < n; ++col) {
        s.clear();
        for(ll row = 0; row < n; ++row) {
            if(s.find(a[row][col]) == s.end()) {
                s.insert(a[row][col]);
            } else {
                dupcols++;
                break;
            }
        }
    }
    cout << "CASE #" << t << ": " << trace << " " << duprows << " " << dupcols << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    for(ll i = 1; i <= t; ++i) {
        ll n;
        cin >> n;
        vector<vector<ll> > a(n, vector<ll> (n));
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        solve(a, n, i);
    }
    return 0;
}