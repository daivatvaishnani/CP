#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << ":" << (x) << " | "

#define for(i, n) for(int i = 0; i < n; ++i)

void test_case() {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(i, n) {
                cin >> arr[i];
        }
        for(i, n) {
                cout << arr[i] << " ";
        }
        cout << "\n";
}

int main() {
        freopen("in", "r", stdin), freopen("out", "w", stdout);
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int t;
        cin >> t;
        while(t--) {
                test_case();
        }
        return 0;
}
