/**
* Problem Link: 
*/              
#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long mul(long long a, long long b) {
    return (a % mod * b % mod) % mod;
}

long long add(long long a, long long b) {
    return (a % mod + b % mod) % mod;
}

long long sub(long long a, long long b) {
    return (mod + a % mod - b % mod) % mod;
}

void test_case(int case_no) {
    int n, k;
    cin >> n >> k;
    long long mod100 = 1, pow2n = 1, sum = 0;
    for(int i = 1; i <= 100; ++i) {
        mod100 = mul(mod100, 10);
    }
    for(int i = 0; i <= n; ++i) {
        pow2n = mul(pow2n, 2);
    }
    sum = pow2n;
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

/*

if(n >= k) {
    d(n, k) = (n - k) + d(n-1, k);
}

(n - k) + (n - k - 1) + (n - k - 2) + .... + (n - k - i)


(n - k + 1)(n - k)/2

*/

