/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void test_case(ll case_no) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = 0, num_p = 0;
    for(ll i = 0; i < k; ++i) {
        if(i == 0 || i == k-1) {
            continue;
        }
        if(a[i] > a[i-1] && a[i] > a[i+1]) {
            num_p++;
        }
    }
    ll max_num_p = num_p, cur_num_p;
    for(ll i = 1; i < n-k+1; ++i) {
        if(a[i] > a[i-1] && a[i] > a[i+1]) {
            num_p--;
        }
        if(a[i+k-2] > a[i+k-3] && a[i+k-2] > a[i+k-1]) {
            num_p++;
        }
        if(num_p > max_num_p) {
            ans = i;
            max_num_p = num_p;
        }
    }
    // cout << ans+1 << " " << ans+k << "\n";
    cout << max_num_p+1 << " " << ans+1 << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    for(ll i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}