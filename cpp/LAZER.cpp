/**
* Problem Link: https://www.codechef.com/MARCH20B/problems/LAZER
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Point {
public:
    ll x, y;
    Point() {}
    Point(ll x, ll y) {
        this->x = x;
        this->y = y;
    }
    string to_string() {
        string sx = std::to_string(x);
        string sy = std::to_string(y);
        return "(x: " + sx + ", y: " + sy + ")";
    }
};

bool operator<(const Point &p1, const Point &p2) {
    if(p1.x == p2.x) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
} 

bool operator>(const Point &p1, const Point &p2) {
    if(p1.x == p2.x) {
        return p1.y > p2.y;
    }
    return p1.x > p2.x;
}

bool operator==(const Point &p1, const Point &p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

class LineSegment {
public:
    Point p1, p2;
    LineSegment() {}
    LineSegment(Point p1, Point p2) {
        this->p1 = p1;
        this->p2 = p2;
    }
    ll cross(Point p) {
        return (p2.x - p1.x) * (p.y - p2.y) - (p.x - p2.x) * (p2.y - p1.y);
    }
    bool intersects(LineSegment segment) {
        // cout << "--------------------------\n";
        // cout << "segment: " << segment.to_string() << "\n";
        ll cross_p1 = this->cross(segment.p1);
        ll cross_p2 = this->cross(segment.p2);
        ll cross_lp1 = segment.cross(p1);
        ll cross_lp2 = segment.cross(p2);
        // cout << "cross " << cross_p1 << " " << cross_p2 << " ";
        if(cross_p1 == 0 && cross_p2 == 0) {
            vector<Point> collinear_points = {p1, p2, segment.p1, segment.p2};
            sort(collinear_points.begin(), collinear_points.end());
            ll same = 0;
            for(ll i = 0; i < 2; ++i) {
                if(collinear_points[i] == p1 || collinear_points[i] == p2) {
                    same++;
                }
            }
            // cout << "same " << same << "\n";
            return same < 2;
        }
        if(p1 == segment.p1 || p1 == segment.p2 || p2 == segment.p1 || p2 == segment.p2) {
            if(segment.p1 == p2 || segment.p2 == p1) {
                return 0;
            }
            // cout << "touched \n";
            return 1;
        }
        if(cross_p1 * cross_p2 < 0 && cross_lp1 * cross_lp2 < 0) {
            return 1;
        }
        // cout << "0\n";
        return 0;
    }
    string to_string() {
        string sp1 = p1.to_string();
        string sp2 = p2.to_string();
        return "{\n\tp1:" + sp1 + ",\n\tp2:" + sp2 + "\n}";
    }
};

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        ll n, q, py;
        cin >> n >> q;
        vector<Point> points(n+1);
        for(ll i = 1; i <= n; ++i) {
            cin >> py;
            points[i] = Point(i, py);
        }
        vector<LineSegment> segments(n);
        for(ll i = 1; i < n; ++i) {
            segments[i] = LineSegment(points[i], points[i+1]);
        }
        while(q--) {
            ll x1, x2, y;
            cin >> x1 >> x2 >> y;
            LineSegment ray_beam(Point(x1, y), Point(x2, y));
            ll total_intersects = 0;
            // cout << "ray beam: " << ray_beam.to_string() << "\n";
            for(ll i = 1; i < n; ++i) {
                if(ray_beam.intersects(segments[i])) {
                    total_intersects++;
                }
            }
            cout << total_intersects << "\n";
            // cout << "Total intersects : " << total_intersects << "\n";
            // cout << "------------------------------------------------------------\n";
        }
    }
    return 0;
}