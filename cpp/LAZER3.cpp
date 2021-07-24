/**
* Problem Link: https://www.codechef.com/MARCH20B/problems/LAZER
*/
#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << ":" << x << " "

typedef long long ll;

bool are_equal_points(double x1, double y1, double x2, double y2) {
    return (x1 == x2 && y1 == y2);
}

bool is_valid_intersection(double x1, double y1, double x2, double y2, double rx1, double rx2, double ry) {
    /*
        Since, the line rx1, rx2, ry is essentially y = ry from (rx1, rx2)
        We'll find the intersection of lines formed by (x1, y1)-(x2, y2) and y = ry
        and check if the intersection lies on both the line segments
    */
    // dbg(x1), dbg(y1), cout << "\n";
    // dbg(x2), dbg(y2), cout << "\n";
    // dbg(rx1), dbg(rx2), dbg(ry), cout << "\n";
    double cy = x2 - x1;
    double cx = y2 - y1;
    double c = y2 * cy - x2 * cx;
    double xi = (ry * cy - c) / cx;
    // dbg(xi), cout << "\n";
    if(xi >= rx1 && xi <= rx2 && xi >= x1 && xi <= x2) {
        /* 
            the intersection lies between (rx1, y)-(rx2, y)
            now the intersection point is valid but we will check for following:
                The beam is considered to collide with a line segment if it intersects or touches this segment, 
                except when 
                    the left endpoint (x1, y1) of this segment is (rx2, ry)
                    the right endpoint (x2, y2) is (rx1, ry).
        */
        bool segments_left_is_rays_right = are_equal_points(x1, y1, rx2, ry);
        bool segments_right_is_rays_left = are_equal_points(x2, y2, rx1, ry);
        // dbg(segments_left_is_rays_right), dbg(segments_right_is_rays_left), cout << "\n";
        if(segments_left_is_rays_right || segments_right_is_rays_left) {
            return 0;
        }
        return 1;
    }
    return 0;
}

ll solve(vector<double> &a, ll n, double x1, double x2, double y) {
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
            // cout << "query " << i + 1 << "\n";
            cout << solve(a, n, x1, x2, y) << "\n";
            // cout << "------------------\n";
        }
    }
    return 0;
}

/*
1
8 1
1 3 3 1 4 4 3 2
2 8 3

1
4 3
1 3 5 1
2 4 4
1 2 3
1 4 1

1 1, 2 3, 

*/