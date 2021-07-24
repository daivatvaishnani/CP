#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, sum, t, segl, maxx, ppd, ppdmax, ppdsummax;
    bool flg;
    string ans;
    cin >> t;
    vector<ll> a;
    vector<pair<ll, ll> > maxe;
    while(t--) {
        sum = 0;
        maxx = LLONG_MIN;
        cin >> n;
        a.resize(n, -1);
        maxe.resize(n, {-1, -1});
        for(ll i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        maxe[0].first = a[0];
        maxe[0].second = 0;
        maxx = max(maxx, maxe[0].first);
        for(ll i = 1; i < n; ++i) {
            if(a[i] >= maxe[i-1].first + a[i]) {
                maxe[i].first = a[i];
                maxe[i].second = i;
            } else {
                maxe[i].first = maxe[i-1].first + a[i];
                maxe[i].second = maxe[i-1].second;
                if(i - maxe[i].second + 1 == n) {
                    ppdmax = -1, ppdsummax = LLONG_MIN;
                    while(maxe[i].second < n) {
                        maxe[i].first -= a[maxe[i].second];
                        maxe[i].second++;
                        if(maxe[i].first >= ppdsummax) {
                            ppdsummax = maxe[i].first;
                            ppdmax = maxe[i].second;
                        }
                    }
                    maxe[i].first = ppdsummax;
                    maxe[i].second = ppdmax;
                }
            }
            maxx = max(maxx, maxe[i].first);
        }
        // cout << "sum:" << sum << ", maxx:" << maxx << "\n";
        // for(int i = 0; i < n; ++i) {
        //     cout << maxe[i].second << " " << maxe[i].first << "\n";
        // }
        ans = (sum > maxx) ? "YES" : "NO";
        cout << ans << "\n";
    }
    return 0;
}