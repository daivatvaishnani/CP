/**
* Problem Link: https://codeforces.com/contest/1321/problem/B
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void prll(vector<ll> &a) {
    for(ll i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> b(n), d(n);
    for(ll i = 0; i < n; ++i) {
        cin >> b[i];
        d[i] = b[i] - i;
    }
    unordered_map<ll, ll> m;
    for(ll i = 0; i < n; ++i) {
        m[d[i]] += b[i];
    }
    ll ans = LLONG_MIN;
    for(auto &p : m) {
        ans = max(ans, p.second);
    }
    cout << ans << "\n";
    return 0;
}

/*
6
10 7 1 9 10 15

1
400000

7
8 9 26 11 12 29 14
*/