/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void test_case(int case_no) {
    int x, y, mx = 0, my = 0;
    string s;
    cin >> x >> y >> s;
    int n = s.length();
    int time = 0, dist, mindist = INT_MAX;
    dist = abs(mx - x) + abs(my - y);
    if(dist <= time) {
        mindist = min(mindist, max(dist, time));
    }
    for(int i = 0; i < n; ++i) {
        time++;
        switch(s[i]) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
        }
        dist = abs(mx - x) + abs(my - y);
        if(dist <= time) {
            mindist = min(mindist, max(dist, time));
        }
    }
    cout << "Case #" << case_no << ": ";
    if(mindist == INT_MAX) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << mindist << "\n";
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}