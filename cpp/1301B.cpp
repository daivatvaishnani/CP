#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll check(ll val, vector<ll> &a, ll n) {
    ll tot = LLONG_MIN, v1, v2;
    for(ll i = 0; i < n-1; ++i) {
        v1 = a[i];
        v2 = a[i+1];
        if(v1 == -1) {
            v1 = val;
        }
        if(v2 == -1) {
            v2 = val;
        }
        tot = max(tot, abs(v1-v2));
    }
    return tot;
}
 
void solve(vector<ll> &a, ll n) {
    unordered_set<ll> adjs;
    for(ll i = 0; i < n; ++i) {
        if(a[i] == -1) {
            if(i-1 >= 0 && a[i-1] != -1) {
                if(adjs.find(a[i-1]) == adjs.end()) {
                    adjs.insert(a[i-1]);
                }
            }
            if(i+1 < n && a[i+1] != -1) {
                if(adjs.find(a[i+1]) == adjs.end()) {
                    adjs.insert(a[i+1]);
                }
            }
        }
    }
    double avg = 0;
    for(ll i : adjs) {
        avg += (double)i;
    }
    if(adjs.size() == 0) {
        // all are -1
        cout << check(110, a, n) << " 110\n";
        return;
    }
    avg /= adjs.size();
    ll c1 = check(ceil(avg), a, n);
    ll c2 = check(floor(avg), a, n);
    ll ans = (c2 <= c1) ? floor(avg) : ceil(avg); 
    cout << min(c1, c2) << " " << ans << "\n";
}
 
int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve(a, n);
    }
    return 0;
}