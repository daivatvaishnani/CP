/**
* Problem Link: https://codeforces.com/contest/1321/problem/0
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, no;
    cin >> n;
    int rob = 0, bio = 0, both = 0, none = 0;
    vector<int> r(n), b(n);
    for(int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for(int i = 0; i < n; ++i) {
        if(r[i] && !b[i]) rob++;
        else if(!r[i] && b[i]) bio++;
        else if(r[i] && b[i]) both++;
        else none++;
    }
    int more_pts_required = bio - rob + 1;
    int ans = 1;
    // cout << rob << " " << bio << "\n";
    if(rob <= 0) {
        cout << "-1\n";
        return 0;
    }
    if(more_pts_required > 0) {
        vector<int> pts(rob, 1);
        // for(int i = 0; i < rob; ++i) {
        //     cout << i << " " << pts[i] << "\n";
        // }
        int j = 0;
        while(more_pts_required > 0) {
            more_pts_required--;
            pts[j]++;
            j = (j + 1) % pts.size();
        }
        // for(int i = 0; i < rob; ++i) {
        //     cout << i << " " << pts[i] << "\n";
        // }
        for(int i = 0; i < rob; ++i) {
            ans = max(ans, pts[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}