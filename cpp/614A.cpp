#include <bits/stdc++.h>

using namespace std;

const int N = 1e9+7;

unordered_set<int> st;

bool a[(int)1e9+1];

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    // clock_t time_req;
    // time_req = clock(); 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, s, k, no;
        cin >> n >> s >> k;
        // st.clear();
        // for(int i = 0; i < k; ++i) {
        //     cin >> no;
        //     no--;
        //     if(st.find(no) == st.end()) {
        //         st.insert(no);
        //     }
        // }
        memset(a, 1, sizeof(a));
        for(int i = 0; i < k; ++i) {
            cin >> no;
            no--;
            a[no] = 0;
        }
        int ml = 0, mr = 0;
        int ts = s-1;
        int ans = 0;
        while(ts >= 0 && /*st.find(ts) != st.end()*/ a[ts] == 0) {
            ml++;
            ts--;
            ans++;
        }
        if(ts < 0) ml = INT_MAX;
        ts = s-1;
        while(ts < n && /*st.find(ts) != st.end()*/ a[ts] == 0) {
            mr++;
            ts++;
            ans++;
        }
        if(ts >= n) mr = INT_MAX;
        cout << min(ml, mr) << "\n";
    }
    // cout << "Processor time taken in pow function: " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}