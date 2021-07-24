/**
* Problem Link: https://codeforces.com/problemset/problem/492/B
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    double l, d = 0;
    cout << std::setprecision(20);
    cin >> n >> l;
    vector<double> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n-1; ++i) {
        d = max(d, (a[i+1] - a[i])/2);
    }
    d = max(d, a[0]);
    d = max(d, l - a[n-1]);
    cout << d << "\n";
    return 0;
}