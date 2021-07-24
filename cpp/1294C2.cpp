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

vector<pair<ll, ll> > factorize(ll n) {
    vector<pair<ll, ll> > factorization;
    unordered_map<ll, ll> powers;
    for (ll d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            powers[d]++;
            n /= d;
        }
    }
    if (n > 1)
        powers[n]++;
    for(auto &p : powers) {
        factorization.push_back({p.first, p.second});
    }
    sort(factorization.begin(), factorization.end());
    return factorization;
}

void print(vector<ll> data = {}) {
    if(data.size() > 0) {
        cout << "YES\n";
        for(ll i : data) cout << i << " ";
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, a, b, c, t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        cout << "CASE : " << i+1 << ", " << "n : " << n << "\n";
        if(n < 8 || isPrime(n)) {
            cout << "NO\n";
            continue;
        }
        vector<pair<ll, ll> > factorization = factorize(n);
        for(auto &p : factorization) cout << p.first << " " << p.second << "\n";
        if(factorization.size() >= 3) {
            a = pow(factorization[0].first, factorization[0].second);
            b = pow(factorization[1].first, factorization[1].second);
            c = 1;
            for(int i = 2; i < factorization.size(); ++i) {
                c = c * pow(factorization[i].first, factorization[i].second);
            }
            print({a, b, c});
            continue;
        }
        if(factorization.size() == 2) {
            vector<ll> factors;
            ll pow;
            for(auto &p : factorization) {
                pow = p.second;
                while(pow--) {
                    factors.push_back(p.first);
                }
            }
            if(factors.size() <= 3) {
                print();
                continue;
            }
            if(factors.size() >= 6) {
                a = factors[0];
                b = factors[1] * factors[2];
                c = 1;
                for(int i = 3; i < factors.size(); ++i) {
                    c = c * factors[i];
                }
                print({a, b, c});
                continue;
            }
            if(factorization[0].second > factorization[1].second) {
                swap(factorization[0], factorization[1]);
            }
            for(auto &p : factorization) {
                cout << p.first << " " << p.second << "--\n";
            }
            a = factorization[0].first;
            b = factorization[1].first;
            c = factorization[0].second == 1 ? b * b : a * a;
            if(factors.size() == 5) {
                c = c * b;
            }
            print({a, b, c});
            continue;
        }
        if(factorization.size() == 1 && factorization[0].second >= 6) {
            a = factorization[0].first;
            b = a * a;
            c = a * a * a;
            print({a, b, c});
            continue;
        }
        print();
    }
    return 0;
}