/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int sum = 0;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        int max_pos = min(sum, m);
        cout << max_pos << "\n";
    }
    return 0;
}