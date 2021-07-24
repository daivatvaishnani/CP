#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void cin_arr(vector<ll> &arr) {
    ll n = arr.size();
    for(ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

ll solve(vector<ll> &a, vector<ll> &b, ll n) {
    ll ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(ll i = n-1; i >= 0; --i) {
        ans += min(a[i], b[i]);
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        cin_arr(a), cin_arr(b);
        cout << solve(a, b, n) << "\n";
    }
    return 0;
}