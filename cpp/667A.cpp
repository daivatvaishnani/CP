/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void test_case(int case_no) {
    ll a, b, ans, diff;
    cin >> a >> b;
    if (a == b) {
        ans = 0;
    } else {
        diff = abs(b - a);
        ans = diff / 10;
        if (diff % 10 != 0) {
            ans++;
        }
    }
    cout << ans << "\n";
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