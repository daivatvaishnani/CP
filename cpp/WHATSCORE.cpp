#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> scores(12, 0);
        while(n--) {
            int a, b;
            cin >> a >> b;
            scores[a] = max(scores[a], b);
        }
        int tot = 0;
        for(int i = 1; i <= 8; ++i) {
            tot += scores[i];
        }
        cout << tot << "\n";
    }
    return 0;
}