#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll, ll> timeid = {
    {12, 0}, {3, 1}, {6, 2}, {9, 3}
};

vector<ll> priceid = {
    25, 50, 75, 100
};

ll go(ll id, ll as, ll at, vector<vector<ll> > &shows, string mask) {
    if(id >= 8) {
        ll ans = 0, sale, price, show, time;
        for(ll i = 0; i < 8; i += 2) {
            price = priceid[i / 2], show = mask[i] - '0', time = mask[i+1] - '0';
            sale = price * shows[show][time];
            ans += sale;
            if(sale == 0) {
                ans -= 100;
            }
        }
        return ans;
    }
    ll ans = LLONG_MIN, nas, nat;
    bool c1, c2; 
    for(int i = 0; i < 4; ++i) {
        nas = as, nat = at;
        c1 = (id & 1 && at & (1 << i));
        c2 = (!(id & 1) && as & (1 << i));
        if (c1 || c2) {
            if(c1) nat = at & ~(1 << i);
            if(c2) nas = as & ~(1 << i);
            ans = max(ans, go(id + 1, nas, nat, shows, mask + to_string(i))); 
        }            
    }
    return ans;
}

ll solve(vector<vector<ll> > &shows) {
    ll ans = 0;
    ans = go(0, 15, 15, shows, "");
    return ans;
} 

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    ll tot = 0;
    while(t--) {
        ll n, time;
        char show;
        cin >> n;
        vector<vector<ll> > shows(4, vector<ll> (4, 0)); 
        for(ll i = 0; i < n; ++i) {
            cin >> show >> time;
            shows[show-'A'][timeid[time]]++;
        }
        ll ans = solve(shows);
        tot += ans;
        cout << ans << "\n";
    }
    cout << tot << "\n";
    return 0;
}