#include <bits/stdc++.h>

using namespace std;

long long solve(long long a, long long b, long long p, string s) {
    long long n = s.length();
    vector<long long> cost(n);
    cost[n-1] = 0;
    if(s[n-2] == s[n-1]) {
        cost[n-1] = (s[n-1] == 'A') ? a : b;
    }
    for(long long i = n-1; i >= 1; --i) {
        cost[i-1] = cost[i];
        if(s[i-1] != s[i]) {
            cost[i-1] = cost[i] + ((s[i-1] == 'A') ? a : b);
        }
    }
    long long ans = 0;
    for(long long i = 0; i < n; ++i) {
        ans++;
        if(cost[i] <= p) {
            break;
        }
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long t;
    cin >> t;
    while(t--) {
        long long a, b, p;
        string s;
        cin >> a >> b >> p >> s;
        cout << solve(a, b, p, s) << "\n";
    }
    return 0;
}