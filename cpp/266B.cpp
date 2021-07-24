/**
* Problem Link: https://codeforces.com/problemset/problem/266/B
*/
#include <bits/stdc++.h>

using namespace std;

void chivalrize(string &s) {
    bool chiv[s.length()];
    memset(chiv, 0, sizeof(chiv));
    for(int i = 0; i < s.length()-1; ++i) {
        if(s[i] == 'B' && s[i+1] == 'G' && !chiv[i] && !chiv[i+1]) {
            swap(s[i], s[i+1]);
            chiv[i] = 1;
            chiv[i+1] = 1;
        }
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t;
    string s;
    cin >> n >> t >> s;
    for(int i = 0; i < t; ++i) {
        chivalrize(s);
    }
    cout << s << "\n";
    return 0;
}