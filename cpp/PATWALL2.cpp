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
    ll n, s, pc;
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

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            pc = cost(i, j);
            cout << "[" << i << "," << j << "]: " << pc << "\n";
            if(s >= pc) {
                ans = max(ans, j-i+1);
            }
        }
    }
    cout << ans << "\n";
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