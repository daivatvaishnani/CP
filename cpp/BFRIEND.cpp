#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> arr;

ll solve(ll n, ll a, ll b, ll c) {
    ll min_cost = LLONG_MAX, cost;
    for(int i = 0; i < n; ++i) {
        cost = abs(b - arr[i]) + abs(arr[i] - a);
        min_cost = min(min_cost, cost);
    }
    return min_cost + c;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        ll n, a, b, c;
        cin >> n >> a >> b >> c;
        arr.resize(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << solve(n, a, b, c) << "\n";
    }
    return 0;
}