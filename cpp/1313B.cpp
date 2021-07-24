#include <bits/stdc++.h>

using namespace std;

int solve(int n, int x, int y) {
    int last = x + y - 1;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        cout << solve(n, x, y) << "\n";
    }
    return 0;
}