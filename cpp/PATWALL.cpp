/**
* Problem Link: '
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<ll, ll> > a, asum;

ll cost(int l, int r) {
    ll ans = 0;
    if(l > r) {
        swap(l, r);
    }
    ans += asum[r].first - asum[l-1].first;
    ll n = r - l + 1;
    ans += n * (asum[r].second - asum[l-1].second);
    return ans;
}

void test_case(int case_no) {
    ll n, s;
    cin >> n >> s;
    a.resize(n+1, {0, 0}), asum.resize(n+1, {0, 0});
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
        asum[i].first = a[i].first;
        asum[i].second = a[i].second;
        asum[i].first += asum[i-1].first;
        asum[i].second += asum[i-1].second;
    }
    for(int i = 1; i <= n; ++i) {
        cout << a[i].first << " " << a[i].second << "\n";
    }
    cout << "\n";
    for(int i = 1; i <= n; ++i) {
        cout << asum[i].first << " " << asum[i].second << "\n";
    }
    // cout << "\n";
    // cout << cost(1, 1) << "\n";
    // cout << cost(2, 2) << "\n";
    // cout << cost(3, 3) << "\n";
    // cout << cost(4, 4) << "\n";
    // for(int i = 1; i <= n; ++i) {
    //     for(int j = i+1; j <= n; ++j) {
    //         cout << "[" << i << "," << j << "]: " << cost(i, j) << "\n";
    //     }
    // }
    priority_queue <ll, vector<ll>, greater<ll>> q; 
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        q.push(a[i])
    }
    cout << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}