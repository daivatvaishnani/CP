#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int firstDigit(int n) { 
    while (n >= 10) {
        n /= 10; 
    }
    return n; 
} 

/*
    A(n), B(m) <= N
    return  no of pairs such that a[1] = b[m] = i, a[n] = b[1] = j
*/
ll solve(ll n) {
    ll total = 0;
    ll cnt[11][11];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++i) {
        cnt[firstDigit(i)][i % 10]++;
    }
    for(int i = 1; i <= 9; ++i) {
        for(int j = 1; j <= 9; ++j) {
            total += cnt[i][j] * cnt[j][i];       
        }
    }
    return total;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}