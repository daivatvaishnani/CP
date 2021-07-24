/**
* Problem Link: https://www.codechef.com/LTIME83B/problems/FFL
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void test_case(ll case_no) {
    ll n, s;
    cin >> n >> s;
    vector<ll> p(n), f(n);
    for(ll i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for(ll i = 0; i < n; ++i) {
        cin >> f[i];
    }
    ll mind = INT_MAX, minf = INT_MAX;
    for(ll i = 0; i < n; ++i) {
        if(!f[i]) {
            mind = min(mind, p[i]);
        } else {
            minf = min(minf, p[i]);
        }
    }
    if(s + mind + minf <= 100) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
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