#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &arr, int n, int m, int k) {
    int ans = -1;
    if(k >= m) {
        k = m-1;
    }
    // remove k elements
    for(int i = 0; i < m; ++i) {
        
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << solve(arr, n, m, k) << "\n";
    }
    return 0;
}