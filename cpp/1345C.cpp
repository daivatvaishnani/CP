/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void test_case(int case_no) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> r(n);
    // unordered_map<long long,int> m;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        r[i] = i;
        // m[r[i]]++;
    }
    bool d = 0;
    for(int k = 1; k <= n; ++k) {
        r[k-1] = k + a[k % n];
    }
    sort(r.begin(), r.end());
    for(int i = 0; i < n-1; ++i) {
        if(r[i] == r[i+1]) {
            d = 1;
            break;
        }
    }
    if(d) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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