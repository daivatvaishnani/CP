/**
* Problem Link: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
*/
#include <bits/stdc++.h>

using namespace std;

bool insert(unordered_set<int> &s, int val) {
    if(s.find(val) == s.end()) {
        s.insert(val);
        return true;
    }
    return false;
}

vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> ans;
    unordered_set<int> dp[n + 1];
    for(int i = 1; i <= 9; ++i) {
        insert(dp[1], i);
    }
    if(n == 1) {
        insert(dp[1], 0);
    }
    for(int i = 2; i <= n; ++i) {
        for(int j : dp[i - 1]) {
            int n1 = j % 10 + k;
            int n2 = j % 10 - k;
            if(n1 >= 0 && n1 <= 9) {
                insert(dp[i], j * 10 + n1);
            }
            if(n2 >= 0 && n2 <= 9) {
                insert(dp[i], j * 10 + n2);
            }
        }
    }
    for(int i : dp[n]) {
        ans.push_back(i);
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> ans = numsSameConsecDiff(n, k);
    for(int i : ans) {
        cout << i << "\n";
    }
    return 0;
}