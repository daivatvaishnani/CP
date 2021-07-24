/**
* Problem Link: 
*/              
#include <bits/stdc++.h>

using namespace std;

void test_case(int case_no) {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n);
    for(int i = 1; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i) {
        cnt[a[i]-1]++;
    }
    for(int i = 0; i < n; ++i) {
        cout << cnt[i] << "\n";
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}