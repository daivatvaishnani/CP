/**
* Problem Link: https://codeforces.com/problemset/problem/230/B
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxx = 1e7 + 6;

bool tprime(ll n, vector<bool> &primes) {
    bool ok = 0;
    if(floor(sqrt(n)) == ceil(sqrt(n))) {
        ll k = sqrt(n);    
        if(primes[k]) {
            ok = 1;
        }
    }
    return ok;
} 

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, no;
    cin >> n;
    vector<bool> primes(maxx, 1);
    primes[1] = 0;
    for(ll i = 2; i*i <= maxx; ++i) {
        if(primes[i]) {
            for(ll j = i*i; j < maxx; j += i) {
                primes[j] = 0;
            }
        }
    }
    for(ll i = 0; i < n; ++i) {
        cin >> no;
        if(tprime(no, primes)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}