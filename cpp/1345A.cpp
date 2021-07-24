/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void test_case(int case_no) {
    int n, m;
    cin >> n >> m;
    bool ans = 0;
    if(n == 1 || m == 1) {
        ans = 1;
    } else if(n == 2 && m == 2) {
        ans = 1;
    }
    if(ans) {
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