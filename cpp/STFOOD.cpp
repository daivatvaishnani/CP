#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &s, vector<int> &v, vector<int> &p) {
    int max_profit = 0.0, profit = 0.0;
    int people = 0, stores = 0;
    for(int i = 0; i < n; ++i) {
        stores = s[i] + 1;
        people = p[i] / stores;
        profit = people * v[i]; 
        if(profit > max_profit) {
            max_profit = profit;
        }
    }
    return max_profit;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> s(n), p(n);
        vector<int> v(n);
        for(int i = 0; i < n; ++i) {
            cin >> s[i] >> p[i] >> v[i];
        }
        cout << solve(n, s, v, p) << "\n";
    }
    return 0;
}