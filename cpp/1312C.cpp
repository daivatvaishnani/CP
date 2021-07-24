/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXX = 1e16 + 1;

bool distinct(vector<ll> &a) {
    unordered_set<ll> s;
    for(ll i : a) {
        if(i != 0) {
            if(s.find(i) != s.end()) {
                return 0;
            }
            s.insert(i);
        }
    }
    return 1;
}

vector<ll> findPowers(ll sum, vector<ll> &kpowers, vector<bool> &taken) {
    ll n = kpowers.size();
    vector<ll> EMP, powers;
    for (ll i = n - 1; i >= 0; i--) { 
        if(sum >= kpowers[i]) {
            if(!taken[i]) {
                sum -= kpowers[i];
                powers.push_back(i);
                taken[i] = 1;
            } else {
                return EMP;
            }
        }
    }
    return powers;
}

bool solve(ll n, ll k, vector<ll> &a) {
    if(!distinct(a)) return 0;
    vector<vector<ll> > powers(n);
    vector<ll> kpowers;
    ll pow = 1;
    while(pow <= MAXX) {
        kpowers.push_back(pow);
        pow = pow * k;
    }
    vector<bool> taken(kpowers.size(), 0);
    for(ll i = 0; i < n; ++i) {
        powers[i] = findPowers(a[i], kpowers, taken);
        // cout << a[i] << ": ";
        // for(ll i : powers[i]) {
        //     cout << k << "^" << i << " ";
        // }
        // cout << "\n";
    }
    for(ll i = 0; i < n; ++i) {
        if(a[i] != 0) {
            if(powers[i].empty()) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t; 
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if(solve(n, k, a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}