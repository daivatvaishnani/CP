#include <bits/stdc++.h>

using namespace std;

int f(string s) {
    int n = s.length();
    int cnt = 0;
    int last = -1;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '1') {
            cnt += (i-last) * (n-i);
            last = i;
        }
    }
    return cnt;
}
int solve(int n, int m) {
    return -1;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    vector<string> strs = {
        "0111",
        "1011",
        "1101",
        "1110",
        "01010"
    };
    for(string s : strs) {
        cout << s << ": " << f(s) << "\n";
    }
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << "\n";
    }
    return 0;
}