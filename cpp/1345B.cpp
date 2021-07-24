/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

const int mh = 4e4;

vector<long long> c(mh);

void test_case(int case_no) {
    long long n;
    cin >> n;
    int ans = 0;
    for(int i = mh-1; i >= 1; --i) {
        if(n <= 0) {
            break;
        }
        if(c[i] <= n) {
            ans++;
            n -= c[i];
        }
    }
    cout << ans << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    c[0] = 0;
    for(int i = 1; i < mh; ++i) {
        c[i] = c[i-1] + 3*i - 1;
    }
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}