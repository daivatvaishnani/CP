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

bool operator!=(const Point &p1, const Point &p2) {
    return !(p1.x == p2.x && p1.y == p2.y);
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
        int val = (p2.x - p1.x) * (p.y - p2.y) - (p.x - p2.x) * (p2.y - p1.y);
        if(val == 0) return 0;
        return (val > 0) ? 1 : -1; 
    }
    bool contains(Point p) {
        return (p.x <= max(p1.x, p2.x) && p.x >= min(p1.x, p2.x) && 
            p.y <= max(p1.y, p2.y) && p.y >= min(p1.y, p2.y));
    }
    bool intersects(LineSegment segment) {
        ll cross_sp1 = this->cross(segment.p1);
        ll cross_sp2 = this->cross(segment.p2);
        ll cross_p1 = segment.cross(p1);
        ll cross_p2 = segment.cross(p2);
        // cout << "--------------------------------------------------------\n";
        // cout << "segment: " << segment.to_string() << "\n";
        // cout << "cross " << cross_sp1 << " " << cross_sp2 << " " << cross_p1 << " " << cross_p2 << "\n";
        if(cross_sp1 != 0 && cross_sp2 != 0 && cross_p1 != 0 && cross_p2 != 0
            && cross_sp1 != cross_sp2  && cross_p1 != cross_p2) {
            // cout << "definite 1\n";
            return 1;
        }
        if(cross_sp1 == 0 && this->contains(segment.p1) && segment.p1 != p2) {
            // cout << "segment p1 on ray_beam 1\n";
            return 1;
        }
        if(cross_sp2 == 0 && this->contains(segment.p2) && segment.p2 != p1) {
            // cout << "segment p2 on ray_beam 1\n";
            return 1;
        }
        if(cross_p1 == 0 && segment.contains(p1) && p1 != segment.p2) {
            // cout << "ray_beam p1 on segment 1\n";
            return 1;
        }
        if(cross_p2 == 0 && segment.contains(p2) && p2 != segment.p1) {
            // cout << "ray_beam p2 on segment 1\n";
            return 1;
        }
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
            // cout << "ray_beam: " << ray_beam.to_string() << "\n";
            for(ll i = 1; i < n; ++i) {
                if(ray_beam.intersects(segments[i])) {
                    total_intersects++;
                }
            }
            cout << total_intersects << "\n";
            // cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        }
    }
    return 0;
}