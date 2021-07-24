/**
* Problem Link: https://codeforces.com/problemset/problem/339/B
*/
#include <bits/stdc++.h>

using namespace std;

long long dist(long long a, long long b, long long n) {
    long long d = (n + b - a) % n;
    return d;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long n, m;
    cin >> n >> m;
    vector<long long> arr(m);
    for(long long i = 0; i < m; ++i) {
        cin >> arr[i];
    }
    long long ans = 0, last = 1;
    for(long long i = 0; i < m; ++i) {
        ans += dist(last, arr[i], n);
        last = arr[i];
    }
    cout << ans << "\n";
    return 0;
}