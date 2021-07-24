/**
* Problem Link: https://codeforces.com/problemset/problem/478/B
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long n, m, minp, maxp, cf, nh;
    cin >> n >> m;
    maxp = ((n - m + 1) * (n - m)) / 2;
    cf = n / m, nh = n % m;
    minp = (cf * (cf - 1) / 2) * (m - nh) + nh * ((cf * (cf + 1)) / 2);
    cout << minp << " " << maxp << "\n";
    return 0;
}