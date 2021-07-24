/**
* Problem Link: https://leetcode.com/problems/trapping-rain-water-ii/
*/
#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int> > &arr) {
    int n = arr.size();
    int m = arr[0].size();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int trapRainWater(vector<vector<int> > &heightMap) {
    int n = heightMap.size();
    int m = heightMap[0].size();
    int trapped = 0;
    vector<vector<int> > u(n, vector<int> (m));
    vector<vector<int> > d(n, vector<int> (m));
    vector<vector<int> > l(n, vector<int> (m));
    vector<vector<int> > r(n, vector<int> (m));
    for(int i = 0; i < n; ++i) {
        l[i][0] = heightMap[i][0]; 
        for(int j = 1; j < m; ++j) {
            l[i][j] = max(l[i][j-1], heightMap[i][j]);
        }
    }
    for(int i = 0; i < n; ++i) {
        r[i][m-1] = heightMap[i][m-1]; 
        for(int j = m-2; j >= 0; --j) {
            r[i][j] = max(r[i][j+1], heightMap[i][j]);
        }
    }
    for(int j = 0; j < m; ++j) {
        u[0][j] = heightMap[0][j]; 
        for(int i = 1; i < n; ++i) {
            u[i][j] = max(u[i-1][j], heightMap[i][j]);
        }
    }
    for(int j = 0; j < m; ++j) {
        d[n-1][j] = heightMap[n-1][j]; 
        for(int i = n-2; i >= 0; --i) {
            d[i][j] = max(d[i+1][j], heightMap[i][j]);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            trapped = min(min(l[i][j], r[i][j]), min(u[i][j], d[i][j])) - heightMap[i][j];
        }
    } 
    print(l), print(r), print(u), print(d);
    return trapped;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<int> > arr = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };
    cout << trapRainWater(arr) << "\n";
    return 0;
}