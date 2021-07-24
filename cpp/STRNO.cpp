/**
* Problem Link: https://www.codechef.com/APRIL20B/problems/STRNO
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> factorize(int n) {
    vector<int> f;
    for (int x = 2; x * x <= n; x++) {
       while (n % x == 0) {
            f.push_back(x);
            n /= x; 
        }
    }
    if (n > 1) {
        f.push_back(n);
    }
    return f;
}

bool isProductOfKNumbers(int x, int k) {
    bool ans = 0;
    vector<int> factors = factorize(x);
    return (factors.size() >= k);
}

int solve(int x, int k) {
    bool ans = (x >= 2);
    if(k > 1) {
        ans &= isProductOfKNumbers(x, k);
    }
    return ans;
}


int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x, k;
        cin >> x >> k;
        cout << solve(x, k) << "\n";
    }
    return 0;
}