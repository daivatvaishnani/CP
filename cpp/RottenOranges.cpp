/**
* Problem Link: https://leetcode.com/problems/rotting-oranges/
*/
#include <bits/stdc++.h>

using namespace std;

void addToQueue(queue<pair<pair<int, int>, int> > &q, int i, int j, 
                vector<vector<int> > &grid, vector<vector<int> > &min_time, int cur) {
        int n = grid.size();
        int m = grid[0].size();
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
            if(min_time[i][j] > cur) {
                q.push({{i, j}, cur});
            }
        }
    }
    
int orangesRotting(vector<vector<int> > &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > min_time(n, vector<int>(m, INT_MAX));
    queue<pair<pair<int, int>, int> > q;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 2) {
                q.push({{i, j}, 0});
            }
        }
    }
    pair<pair<int, int>, int> pr;
    int prx, pry, cur;
    while(!q.empty()) {
        pr = q.front();
        prx = pr.first.first;
        pry = pr.first.second;
        cur = pr.second;
        if(min_time[prx][pry] > cur) {
            min_time[prx][pry] = cur;
            addToQueue(q, prx + 1, pry, grid, min_time, cur + 1);
            addToQueue(q, prx - 1, pry, grid, min_time, cur + 1);
            addToQueue(q, prx, pry + 1, grid, min_time, cur + 1);
            addToQueue(q, prx, pry - 1, grid, min_time, cur + 1);
        }
        q.pop();    
    }
    int time = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] != 0) {
                time = max(time, min_time[i][j]);
            }
        }
    }
    if(time == INT_MAX) {
        time = -1;
    }
    return time;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<int> > grid = {
        {2,1,1}, 
        {0,1,1},
        {1,0,1}
    };
    cout << orangesRotting(grid) << "\n";
    return 0;
}

/*
    vector<vector<int> > grid = {
        {2,1,1}, 
        {1,1,0},
        {0,1,1}
    };

    vector<vector<int> > grid = {
        {2,1,1}, 
        {0,1,1},
        {1,0,1}
    };
 */ 