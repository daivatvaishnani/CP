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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int> > cnt(2);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            cnt[a[i] % 2].push_back(i);
        }
        if(cnt[0].size() > 0) {
            cout << "1\n";
            cout << cnt[0][0] + 1 << "\n";
        } else if(cnt[1].size() > 1) {
            cout << "2\n";
            cout << cnt[1][0] + 1 << " " << cnt[1][1] + 1 << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}