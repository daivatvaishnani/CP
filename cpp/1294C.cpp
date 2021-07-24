#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPrime(ll x) {
    for (ll d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, a, b, c, t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        // cout << "CASE: " << i+1 << "\n"; 
        cin >> n;
        // cout << "n: " << n << "\n";
        if(n < 8 || isPrime(n)) {
            cout << "NO\n";
            continue;
        }
        vector<ll> prime_factors = trial_division1(n);
        // for(ll p : prime_factors) cout << p << " ";
        // cout << "\n";
        if(prime_factors.size() >= 6) {
            a = prime_factors[0];
            b = prime_factors[1]*prime_factors[2];
            c = 1;
            for(int i = 3; i < prime_factors.size(); ++i) {
                c = c * prime_factors[i];
            }
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
            continue;
        } 
        vector<pair<ll, ll> > chu;
        ll last = -1, cnt = -1;
        for(ll p : prime_factors) {
            if(last != p) {
                if(last != -1 && cnt != -1) {
                    chu.push_back({last, cnt});
                }
                last = p;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if(last != -1 && cnt != -1) {
            chu.push_back({last, cnt});
        }
        // for(auto &p : chu) cout << "(" << p.first << ", " << p.second << ") ";
        // cout << "\n";
        if(chu.size() >= 3) {
            cout << "YES\n";
            a = pow(chu[0].first, chu[0].second);
            b = pow(chu[1].first, chu[1].second);
            c = 1;
            for(int i = 2; i < chu.size(); ++i) {
                c = c * pow(chu[i].first, chu[i].second);
            }
            cout << a << " " << b << " " << c << "\n";
            continue;
        }
        if(chu.size() == 1) {
            cout << "NO\n";
            continue;
        }
        if(prime_factors.size() <= 3) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if(chu[0].second > chu[1].second) {
            swap(chu[0], chu[1]);
        }
        if(prime_factors.size() == 4) {
            if(chu[0].second == 1) {
                a = chu[0].first;
                b = chu[1].first;
                c = chu[1].first * chu[1].first;
            } else {
                a = chu[0].first;
                b = chu[1].first;
                c = chu[0].first * chu[1].first;
            }
        } else {
            if(chu[0].second == 1) {
                a = chu[0].first;
                b = chu[1].first;
                c = chu[1].first * chu[1].first * chu[1].first; 
            } else {
                a = chu[0].first;
                b = chu[1].first;
                c = chu[0].first * chu[1].first * chu[1].first;
            }
        } 
        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}