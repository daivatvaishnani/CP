/**
* Problem Link: 
*/              
#include <bits/stdc++.h>

using namespace std;

void test_case(int case_no) {
    long long n;
    int m;
    cin >> n >> m;
    vector<long long> arr(m);
    long long sum = 0;
    for(int i = 0; i < m; ++i) {
        cin >> arr[i];
        sum += 1LL * arr[i];
    }
    if(n - sum < 0) {
        cout << "-1\n";
    } else {
        cout << n - sum << "\n";
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