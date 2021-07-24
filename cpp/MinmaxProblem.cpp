#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;

void solve_slow(vvi &arr) {
    ll n = arr.size()-1, m = arr[0].size()-1;
    ll minMax = LLONG_MIN, minMaxx, maxx;
    ll a1 = -1, a2 = -1;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; ++j) {
            minMaxx = LLONG_MAX;
            // cout << "(" << i << ", " << j << ")\n";
            for(ll k = 1; k <= m; ++k) {
                maxx = max(arr[i][k], arr[j][k]);
                cout << maxx << " ";
                minMaxx = min(minMaxx, maxx);
            }
            cout << "\n";
            if(minMax < minMaxx) {
                minMax = minMaxx;
                a1 = i, a2 = j;
            }
        }
        cout << "\n";
    }
    cout << "MinMax : " << minMax << "\n";
    cout << a1 << " " << a2 << "\n";
    return;
}

void solve(vvi &arr) {
    ll n = arr.size()-1, m = arr[0].size()-1;
    ll a1 = -1, a2 = -1;
    v 
    cout << a1 << " " << a2 << "\n";
    return;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vvi arr(n+1, vi (m+1));
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }
    solve_slow(arr);
    solve(arr);
    return 0;
}