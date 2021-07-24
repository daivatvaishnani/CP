/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int dp[maxn], a1[maxn], a2[maxn];

void test_case(int case_no) {
    int x, n, m;
    cin >> x >> n >> m;
    while(x > 20) {
        if(n > 0) {
            x = x / 2 + 10;
            n--;
        } else if(m > 0) {
            x = x - 10;
            m--;
        } else {
            cout << "NO\n";
            return;
        }
    }
    while(x > 0) {
        if(m > 0) {
            x = x - 10;
            m--;
        } else {
            cout << "NO\n";
            return;
        }
    }
    if(x <= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}