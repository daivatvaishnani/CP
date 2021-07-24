#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void prll_arr(vector<ll> &a) {
    for(ll i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

ll solve(vector<ll> &a, ll n, ll k) {
    vector<ll> modk(n), divk(n);
    for(ll i = 0; i < n; ++i) {
        modk[i] = a[i] % k;
        divk[i] = a[i] / k;
    }
    vector<ll> nd(n);
    for(ll i = 0; i < n; ++i) {
        if(modk[i] != 0) {
            nd[i] = k - modk[i];
        }
    }
    vector<ll> sp(n), spk(n), ndt(n);
    sp[0] = modk[0];
    spk[0] = divk[0];
    ndt[n-1] = nd[n-1];
    for(ll i = 1; i < n; ++i) {
        sp[i] = sp[i-1] + modk[i];
        spk[i] = spk[i-1] + divk[i];
    }
    for(ll i = n-2; i >= 0; --i) {
        ndt[i] = ndt[i+1] + nd[i];
    }
    // cout << k << "\n";
    // cout << "a\t\t:\t"; prll_arr(a);
    // cout << "modk\t:\t"; prll_arr(modk);
    // cout << "divk\t:\t"; prll_arr(divk);
    // cout << "nd\t\t:\t"; prll_arr(nd);
    // cout << "sp\t\t:\t"; prll_arr(sp);
    // cout << "spk\t\t:\t"; prll_arr(spk);
    // cout << "ndt\t\t:\t"; prll_arr(ndt);
    ll mind = LLONG_MAX, cd;
    // case c in [1, n-1]
    for(ll c = 0; c < n-1; ++c) {
        ll ck;
        if(sp[c] + spk[c] * k >= ndt[c+1]) {
            // cout << c << "\t\t:\t" << sp[c] << " " <<  spk[c] << " " << ndt[c+1] << "\n"; 
            ck = ceil((ndt[c+1] - sp[c] + 0.0) / k);
            cd = sp[c] + ck * k - ndt[c+1];
            mind = min(cd, mind);
        }
    }
    // case c = 0
    if(ndt[0] == 0) {
        mind = min(mind, 0LL);
    }
    // case c = n
    mind = min(mind, sp[n-1]);
    return mind;
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
        // cout << "------------------\n";
    }
    return 0;
}