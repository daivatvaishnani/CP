/**
* Problem Link: https://www.codechef.com/MARCH20B/problems/ADASHOP2
*/
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > find_path_to_11(int r, int c) {
    vector<pair<int, int> > path_to_11 = {{(r + c)/2, (r + c)/2}};
    if(r + c != 2) {
        path_to_11.push_back({1, 1});
    }
    return path_to_11;
}

vector<pair<int, int> > find_path(int r, int c) {
    vector<pair<int, int> > path_from_11 = {
        {2, 2}, {1, 3}, {3, 1},
        {4, 2}, {5, 1}, {1, 5},
        {2, 6}, {1, 7}, {7, 1},
        {8, 2}, {2, 8},
        {3, 7}, {4, 8}, {8, 4},
        {7, 5}, {8, 6}, {6, 8},
        {7, 7}, {8, 8} 
    };
    if(r == 1 && c == 1) {
        return path_from_11;
    } else {
        vector<pair<int, int> > path_from_rc = find_path_to_11(r, c);
        path_from_rc.insert(path_from_rc.end(), path_from_11.begin(), path_from_11.end());
        return path_from_rc;
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, r, c;
    cin >> t;
    while(t--) {
        cin >> r >> c;
        vector<pair<int, int> > path = find_path(r, c);
        cout << path.size() << "\n";
        for(auto p : path) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}