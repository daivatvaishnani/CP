/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 32;

ll pow2[maxn];

void test_case(ll case_no) {
    ll n;
    cin >> n;    
    ll d0 = pow2[n], d1 = 0;
    for(int i = 1; i <= n/2-1; ++i) {
        d0 += pow2[i];
    }
    for(int i = n/2; i < n; ++i) {
        d1 += pow2[i];
    }
    cout << abs(d0-d1) << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    pow2[0] = 1;
    for(ll i = 1; i <= 30; ++i) {
        pow2[i] = pow2[i-1] * 2;
    }
    ll t;
    cin >> t;
    for(ll i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}