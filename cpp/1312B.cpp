/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &a, int n) {
    vector<int> b = a;
    sort(b.rbegin(), b.rend());
    for(int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve(a, n);
    }
    return 0;
}