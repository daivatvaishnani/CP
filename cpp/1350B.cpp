/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void test_case(int case_no) {
    int n;
    cin >> n;
    vector<int> s(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    vector<int> dp(n+1, 1);
    int ans = 1;
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j*j <= i; ++j) {
            if(i % j == 0) {
                if(s[j] < s[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                if(s[i/j] < s[i]) {
                    dp[i] = max(dp[i], dp[i/j] + 1);
                }
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}