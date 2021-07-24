#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t, n, a, b, maxs;
    cin >> t;
    while(t--) {
        cin >> n;
        maxs = INT_MIN;
        while(n--) {
            cin >> a >> b;
           if(a < 8 && a > 0) maxs = max(maxs, b);
        }
        cout << maxs << "\n";    
    }
    return 0;
}
