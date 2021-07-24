/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void test_case(int case_no) {
    long long n, k, ans, div;
    cin >> n >> k;
    if(n & 1) {
        div = -1;
        for(int i = 2; i*i <= n; ++i) {
            if(n % i == 0) {
                div = i;
                break;
            }
        }
        if(div == -1) {
            div = n;
        }
        ans = n + div + (k-1) * 2;
    } else {
        ans = n + 2 * k;
    }
    cout << ans << "\n";
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