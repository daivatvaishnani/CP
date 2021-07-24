/**
* Problem Link: https://www.codechef.com/APRIL20B/problems/SQRDSUB
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 5;

ll find_with_sum(vector<ll> &a, ll k, ll n) {
    ll sum = 0, ans = 0;
    unordered_map<ll, ll> mp;
    for(ll i = 1; i <= n; ++i) {
        sum += a[i];
        if(sum == k) {
            ans++;
        }
        if(mp.find(sum - k) != mp.end()) {
            ans += mp[sum - k];
        }
        mp[sum]++;
    }
    return ans;
}

void test_case() {
    ll n, no, pow2;
    cin >> n;
    vector<ll> pow(n+1, 0);
    for(ll i = 1; i <= n; ++i) {
        cin >> no;
        pow2 = 0;
        while((no & 1) != 1) {
            pow2++;
            no /= 2;
            if(pow2 >= 2) {
                break;
            }
        }
        pow[i] = pow2;
    }
    ll ans1 = find_with_sum(pow, 1, n);
    ll ans = (n * (n + 1))/2 - ans1;
    cout << ans << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        test_case();
    }
    return 0;
}