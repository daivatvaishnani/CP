#include <bits/stdc++.h>

using namespace std;

class Point {
public:
    int x, y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

bool cmp(Point &p1, Point &p2) {
    if(p1.x == p2.x) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

vector<Point> v;

string path(Point &p1, Point &p2) {
    string rs = string(p2.x - p1.x, 'R');
    string us = string(p2.y - p1.y, 'U');
    return rs + us;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        v.resize(n, Point(-1, -1));
        for(int i = 0; i < n; ++i) {
            cin >> v[i].x >> v[i].y;
        }
        sort(v.begin(), v.end(), cmp);
        bool wrong = 0;
        // for(Point &p : v) {
        //     cout << p.x << " " << p.y << "\n";
        // }
        for(int i = 1; i < n; ++i) {
            if(v[i].x < v[i-1].x || v[i].y < v[i-1].y) {
                wrong = 1;
                break;
            } 
        }
        if(wrong) {
            cout << "NO\n";
            continue;
        }
        Point origin = Point(0, 0);
        string ans = path(origin, v[0]);
        for(int i = 1; i < n; ++i) {
            ans += path(v[i-1], v[i]);
        }
        cout << "YES\n" << ans << "\n";
    }
    return 0;
}