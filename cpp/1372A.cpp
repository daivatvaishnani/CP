/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void test_case(int case_no) {
    int n;
    cin >> n;
    vector<int> a(1000);
    for(int i = 0; i < min(n, 500); ++i) {
        a[i] = 2*i + 1;
    }
    for(int i = 500; i < max(n, 500); ++i) {
        a[i] = 1;
    }
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
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