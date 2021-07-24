// https://codeforces.com/contest/1315/problem/0

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long t;
    cin >> t;
    while(t--) {
        long long a, b, x, y;
        cin >> a >> b >> x >> y;
        long long a1 = x*b, a2 = a*y, a3 = (a-x-1)*b, a4 = a*(b-y-1);
        cout << max(a1, max(a2, max(a3, a4))) << "\n";
    }
    return 0;
}