/**
* Problem Link: https://www.codechef.com/LTIME82B/problems/PRFXGD
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, k, x;
    string s;
    cin >> t;
    int cnt[32];
    while(t--) {
        cin >> s >> k >> x;
        memset(cnt, 0, sizeof(cnt));
        int deleted = 0, ans = 0;
        for(int i = 0; i < s.length(); ++i) {
            int c = s[i] - 'a';
            cnt[c]++;
            if(cnt[c] > x) {
                if(deleted >= k) {
                    break;
                } else {
                    cnt[c]--;
                    deleted++;
                }
            } else {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}