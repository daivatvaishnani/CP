#include <bits/stdc++.h>

using namespace std;

string solve(string a, string b, string c) {
    int n = a.length();
    bool ok = 1;
    string ans = "YES";
    for(int i = 0; i < n; ++i) {
        ok &= (c[i] == b[i] || c[i] == a[i]);
    }
    if(!ok) {
        ans = "NO";
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << "\n";
    }
    return 0;
}