#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

const int maxd = 998244353;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, maxin = INT_MIN, n;
    string s;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        s = string(n/2, '1');
        if(n & 1) s[0] = '7';
        cout << s << "\n";    
    }
    return 0;
}