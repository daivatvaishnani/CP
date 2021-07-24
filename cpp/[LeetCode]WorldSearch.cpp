/**
* Problem Link: https://leetcode.com/problems/word-search/
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> xoff = {1, 0, -1, 0};
vector<int> yoff = {0, 1, 0, -1};

int numNeighbours = 4;

bool match(int i, int j, vector<vector<char>> &board, 
            string &word, int pos, vector<vector<bool>> visited) {
    if(pos >= word.size()) {
        return true;
    }
    if(pos == word.size() - 1) {
        return board[i][j] == word[pos];
    }
    visited[i][j] = true;
    bool matched = false;
    int n = board.size();
    int m = board[0].size();
    if(board[i][j] == word[pos]) {
        for(int k = 0; k < numNeighbours; ++k) {
            int x = i + xoff[k];
            int y = j + yoff[k];
            if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                matched = match(x, y, board, word, pos+1, visited);
                if(matched) {
                    break;
                }
            }
        }
    }
    return matched;
}

bool exist(vector<vector<char>> &board, string word) {
    int n = board.size();
    int m = board[0].size();
    bool matched = false;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == word[0]) {
                vector<vector<bool>> visited(n, vector<bool>(m));
                matched = match(i, j, board, word, 0, visited);
                if(matched) {
                    return true;
                }
            }
        }
    }
    return matched;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    vector<vector<char>> board1 = {
        {'a','b'},
        {'c','d'}
    };
    vector<pair<vector<vector<char>>,pair<string,bool>>> test_cases = {
        {board,{"SEE", true}},
        {board,{"ABCCED", true}},
        {board,{"ABCB", false}},
        {board1,{"bacd", true}}
    };
    for(int i = 0; i < test_cases.size(); ++i) {
        bool ans = exist(test_cases[i].first, test_cases[i].second.first);
        cout << "Test Case #" << i+1 << ": ";
        if(ans == test_cases[i].second.second) {
            cout << "PASSED\n";
        } else {
            cout << "FAILED\n";
        }
    }
    return 0;
}