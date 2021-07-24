/**
* Problem Link: https://www.codechef.com/MARCH20B/problems/LAZER
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool are_equal_points(double x1, double y1, double x2, double y2) {
    return (x1 == x2 && y1 == y2);
}

bool is_valid_intersection(double x1, double y1, double x2, double y2, double rx1, double rx2, double ry) {
    double cy = x2 - x1;
    double cx = y2 - y1;
    double c = y2 * cy - x2 * cx;
    double xi = (ry * cy - c) / cx;
    if(xi >= rx1 && xi <= rx2 && xi >= x1 && xi <= x2) {
        bool segments_left_is_rays_right = are_equal_points(x1, y1, rx2, ry);
        bool segments_right_is_rays_left = are_equal_points(x2, y2, rx1, ry);
        if(segments_left_is_rays_right || segments_right_is_rays_left) {
            return 0;
        }
        return 1;
    }
    return 0;
}

ll solve_slow(vector<double> &a, ll n, double x1, double x2, double y) {
    ll count = 0;
    for(ll i = 1; i < n; ++i) {
        if(is_valid_intersection(i+0.0, a[i-1], i+1.0, a[i], x1, x2, y)) {
            count++;
        }
    }
    return count;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        ll n, q;
        double x1, x2, y;
        cin >> n >> q;
        vector<double> a(n);
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < q; ++i) {
            cin >> x1 >> x2 >> y;
            cout << solve_slow(a, n, x1, x2, y) << "\n";
        }
    }
    return 0;
}