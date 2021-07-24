/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

bool removable(int i, string &s) {
    int len = s.length();
    int c = s[i] - 'a', p = 100, n = 100;
    if(i - 1 >= 0) p = s[i - 1] - 'a';
    if(i + 1 < len) n = s[i + 1] - 'a';
    return (c - p == 1 || c - n == 1);
}

string remove(int i, string &s) {
    int n = s.length();
    string left = s.substr(0, i);
    string right = s.substr(i + 1, n - i);
    string ns = left + right;
    return ns;
}

int solve_slow(int n, string &s, unordered_map<string, int> &dp,  unordered_map<int, vector<pair<string, int> > > &removed) {
    if(dp.find(s) != dp.end()) {
        return dp[s];
    }
    cout << s << "\n";
    int ans = 0;
    if(n > 1) {
        for(int i = 0; i < n; ++i) {
            if(removable(i, s)) {
                string ns = remove(i, s);
                ans = max(ans, solve_slow(n-1, ns, dp, removed) + 1);
            }
        }
    }
    removed[n].push_back({s, ans});
    dp[s] = ans;
    return ans;
}

int solve(int n, string &s) {
    vector<int> a(n), prev(n), next(n);
    if(n == 1) {
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        a[i] = s[i] - 'a';
        if(i == 0) {
            prev[i] = -10;
            next[i] = a[1];
        }
        else if(i == n - 1) {
            prev[i] = a[n - 2];
            next[i] = -10;
        } else {
            prev[i] = a[i - 1];
            next[i] = a[i + 1];
        }
    }
    
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    unordered_map<string, int> dp;
    unordered_map<int, vector<pair<string, int> > > removed;
    cout << solve_slow(n, s, dp, removed) << "\n";
    for(auto &p : removed) {
        cout << p.first << ":\n";
        for(auto sp : p.second) {
            cout << "{" << sp.first << ", " << sp.second << "}\n";
        }
        cout << "\n";
    }
    return 0;
}