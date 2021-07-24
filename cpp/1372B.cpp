/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void test_case(int case_no) {
    ll n;
    cin >> n;
    ll mk = LLONG_MAX;
    for(int i = 2; i*i <= n; ++i) {
        if(n % i == 0) {
            ll a1 = i, a2 = n/i;
            mk = min(mk, n/a1 - 1);
            mk = min(mk, n/a2 - 1);
        }
    }
    ll ans1 = n/(1+mk), ans2 = mk*n/(1+mk);
    if(mk == LLONG_MAX) {
        ans1 = 1, ans2 = n - 1;
    }
    cout << ans1 << " " << ans2 << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}