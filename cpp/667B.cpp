/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get(ll a, ll b, ll x, ll y, ll n) {
    ll da = min(a - x, n);
    a -= da;
    n -= da;
    ll db = min(b - y, n);
    b -= db;
    return a * b;
}

void test_case(int case_no) {
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    cout << min(get(a, b, x, y, n), get(b, a, y, x, n)) << "\n"; 
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