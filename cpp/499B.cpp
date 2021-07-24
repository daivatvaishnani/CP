/**
* Problem Link: https://codeforces.com/problemset/problem/499/B
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    string s, t;
    cin >> n >> m;
    unordered_map<string, string> ot;
    for(int i = 0; i < m; ++i) {
        cin >> s >> t;
        ot[s] = t;
    }
    for(int i = 0; i < n; ++i) {
        cin >> s;
        if(s.length() > ot[s].length()) {
            cout << ot[s] << " ";
        } else {
            cout << s << " ";
        }
    }
    return 0;
}