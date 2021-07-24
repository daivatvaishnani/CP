/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
    int adjacents = 4;
    vector<int> xoff = {0, 1, 0, -1};
    vector<int> yoff = {1, 0, -1, 0};

    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
public:
    int orangesRotting(vector<vector<int> > &grid) {
        int n = grid.size();
        if(n == 0) {
            return -1;
        }
        int m = grid[0].size();
        if(m == 0) {
            return -1;
        }
        vector<vector<int> > timeTaken(n, vector<int> (m, -1));
        queue<pair<int, int> > queue;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 2) {
                    timeTaken[i][j] = 0;
                    queue.push({i, j});
                }
            }
        }
        while(!queue.empty()) {
            pair<int, int> node = queue.front();
            for(int i = 0; i < adjacents; ++i) {
                int x = node.first + xoff[i];
                int y = node.second + yoff[i];
                if(isValid(x, y, n, m)) {
                    if(grid[x][y] == 1 && timeTaken[x][y] == -1) {
                        timeTaken[x][y] = timeTaken[node.first][node.second] + 1;
                        queue.push({x, y});
                    }
                }
            }
            queue.pop();
        }
        int minTimeTaken = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] != 0) {
                    if(timeTaken[i][j] == -1) {
                        return -1;
                    }
                    minTimeTaken = max(minTimeTaken, timeTaken[i][j]);
                }
            }
        }
        return minTimeTaken;
    }
};

/*
2 1 1
1 1 0
0 1 1

1 2 3
2 3 -1
-1 4 5
*/


int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<int> > grid = {{2,1,1},{1,1,0},{0,1,1}};
    Solution solver;
    cout << solver.orangesRotting(grid) << "\n";
    return 0;
}