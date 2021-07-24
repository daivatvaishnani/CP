#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void ins(unordered_map<ll, ll> &m, ll i) {
    m[i]++;
}

void rem(unordered_map<ll, ll> &m, ll i) {
    m[i]--;
    if(m[i] <= 0) {
        m.erase(i);
    }
}

void prll_map(unordered_map<ll, ll> &m) {
    cout << "----- MAP -----\n";
    for(auto &p : m) {
        cout << p.first << ": " << m[p.first] << "\n";
    }
    cout << "---------------\n";
}

void prll(vector<ll> &a) {
    for(ll i = 0; i < a.size(); ++i) {
        cout << i << ": " << a[i] << "\n";
    }
    cout << "\n";
}

ll solve(vector<ll> &a, ll n, ll k) {
    // prll(a);
    unordered_map<ll, ll> count;
    count.clear();
    ll maxlen = 0, start = 0;
    for(ll i = 0; i < n; ++i) {
        ins(count, a[i]);
        if(count.size() == k) {
            // cout << "start: " << start << ", i: " << i << ", len: " << i-start << "\n";
            maxlen = max(maxlen, i-start);
            ll j;
            for(j = start; j < i; ++j) {
                rem(count, a[j]);
                if(count.size() < k) {
                    break;
                }
            }
            start = j+1;
            // cout << "start: " << start << "\n";
        }
    }
    maxlen = max(maxlen, n-start);
    return maxlen;
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
        cout << solve(a, n, k) << "\n";
    }
    return 0;
}
