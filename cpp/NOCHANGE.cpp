#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void prll_ans(bool ok, vector<ll> &qt) {
    cout << (ok ? "YES" : "NO");
    if(ok) {
        for(ll i : qt) {
            cout << " " << i;
        }
    }
    cout << "\n";
}

void print_arr(vector<ll> &a) {
    for(ll i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

void print_arrarr(vector<vector<ll> > &arr) {
    for(auto v : arr) {
        print_arr(v);
    }
}

void solve(vector<ll> &d, ll n, ll p) {
    bool every = 1;
    vector<ll> qt(n, 0);
    for(ll i = 0; i < n; ++i) {
        every &= (p%d[i] == 0);
        if(!every) {
            qt[i] = p/d[i] + 1;
            prll_ans(1, qt);
            return;
        }
    }
    for(ll i = 0; i < n-1; ++i) {
        for(ll j = i+1; j < n; ++j) {
            if(d[j]%d[i] != 0) {
                qt[i] = p/d[i] - 1;
                qt[j] = 1;
                prll_ans(1, qt);
                return;
            }
        }
    }
    prll_ans(0, qt);
    return;
}

bool overpays(vector<ll> &qty, vector<ll> &d, ll n, ll p) {
    bool strict = 1;
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += qty[i] * d[i];
    }
    strict &= (sum > p);
    for(int i = 0; i < n; ++i) {
        if(qty[i]) {
            strict &= (sum - d[i] < p); 
        }
    }
    return strict;
}

void go(ll i, vector<ll> &d, ll n, ll p, vector<ll> qty, vector<vector<ll> > &qtys) {
    if(i >= n) {
        // print_arr(qty);
        if(overpays(qty, d, n, p)) {
            qtys.push_back(qty);
        }
        return;
    }
    if(qty[i] * d[i] <= p) {
        qty[i]++;
        go(i, d, n, p, qty, qtys);
        qty[i]--;
    }
    go(i+1, d, n, p, qty, qtys);
}

void solve_slow(vector<ll> &d, ll n, ll p) {
    vector<ll> qty(n);
    vector<vector<ll> > qtys;
    go(0, d, n, p, qty, qtys);
    // print_arrarr(qtys);
    if(qtys.size() > 0) {
        prll_ans(1, qtys[0]);
        return;
    }
    prll_ans(0, qtys[0]);
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        ll n, p;
        cin >> n >> p;
        vector<ll> d(n);
        for(ll i = 0; i < n; ++i) {
            cin >> d[i];
        }
        solve(d, n, p);
        solve_slow(d, n, p);
    }   
    return 0;
}