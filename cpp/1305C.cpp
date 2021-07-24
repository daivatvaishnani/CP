/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a;

int add(int a, int b) {
    return (a % m + b % m) % m;
}

int mul(int a, int b) {
    return ((a % m) * (b % m)) % m;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int tot = 1;
    for(int i = 0; i < n-1; ++i) {
        for(int j = i+1; j < n; ++j) {
            tot = mul(tot, abs(a[i]-a[j]));
        }
    }
    cout << tot << "\n";
    return 0;
}