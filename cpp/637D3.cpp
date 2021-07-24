/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

vector<string> digits = {
    "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

int find_dist(string &s, int digit) {
    string d = digits[digit];
    int off = 0;
    for(int i = 0; i < 7; ++i) {
        if(d[i] == '1' && s[i] == '0') {
            off++;
        }
        if(d[i] == '0' && s[i] == '1') {
            return -1;
        }
    }
    return off;
}

int find_digit(string &s) {
    for(int i = 0; i < digits.size(); ++i) {
        if(s == digits[i]) {
            return 1;    
        }
    }
    return 0;
}

void test_case(int case_no) {
    int n, k;
    cin >> n >> k;
    string nums[n];
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<vector<int>> dist(n+1, vector<int>(10));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 10; ++j) {
            dist[i][j] = find_dist(nums[i], j);
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    dp[n][0] = 1;
    for(int i = n; i > 0; --i) {
        for(int j = 0; j <= k; ++j) {
            if(dp[i][j]) {
                for(int d = 0; d < 10; ++d) {
                    if(dist[i-1][d] != -1 && j + dist[i-1][d] <= k) {
                        dp[i-1][j + dist[i-1][d]] = 1;
                    }
                }
            }
        }
    }
    if(dp[0][k] == 0) {
        cout << "-1\n";
        return;
    }
    for(int i = 0; i < n; ++i) {
        int mx = -1;
        for(int d = 9; d >= 0; --d) {
            if(dist[i][d] != -1 && k >= dist[i][d] && dp[i+1][k - dist[i][d]]) {
                mx = d;
                k -= dist[i][d];
                break;
            }
        }
        assert(mx != -1);
        cout << mx;
    }
    cout << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}
