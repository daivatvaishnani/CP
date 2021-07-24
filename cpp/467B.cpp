/**
* Problem Link: https://codeforces.com/problemset/problem/467/B
*/
#include <bits/stdc++.h>

using namespace std;

bool cbf(int a, int b, int k) {
    bool ca, cb;
    int d = 0;
    for(int i = 0; i < 20; ++i) {
        ca = (1 << i) & a;
        cb = (1 << i) & b;
        if(ca != cb) {
            d++;
        }
    }
    return d <= k;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(m+1);
    for(int i = 0; i < m+1; ++i) {
        cin >> arr[i];
    }
    int ans = 0;
    for(int i = 0; i < m; ++i) {
        ans += cbf(arr[i], arr[m], k);
    }
    cout << ans << "\n";
    return 0;
}