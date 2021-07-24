#include <bits/stdc++.h>
#include "printutils.h"

using namespace std;

int maximalSquare2(vector<vector<char>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> maxs(n, vector<int>(m, 0));
  int maxa = 0;
  cout << "matrix:\n";
  print2DArray(matrix);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (matrix[i][j] == '1') {
        maxs[i][j] = 1;
        if (i >= 1 && j >= 1 
            && maxs[i-1][j-1] > 0
            && i >= maxs[i-1][j-1] && j >= maxs[i-1][j-1]) {
          maxs[i][j] += min(maxs[i-1][j-1], min(maxs[i][j-1], maxs[i-1][j]));
        }
      }
      maxa = max(maxa, maxs[i][j]);
    }
  }
  cout << "maxs:\n";
  print2DArray(maxs);
  return maxa * maxa;
}

int maximalSquare(vector<vector<char>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> maxs(n, vector<int>(m, 0));
  int maxa = 0;
  cout << "matrix:\n";
  print2DArray(matrix);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (matrix[i][j] == '1') {
        maxs[i][j] = 1;
        if (i >= 1 && j >= 1 
            && maxs[i-1][j-1] > 0
            && i >= maxs[i-1][j-1] && j >= maxs[i-1][j-1]) {
          bool row = 1, col = 1;
          for (int k = 1; k <= maxs[i-1][j-1]; ++k) {
            row = row && matrix[i][j-k] == '1';
            col = col && matrix[i-k][j] == '1'; 
            if (!row || !col) {
              break;
            }
            if (row && col) {
              maxs[i][j]++;
            }
          }
        }
      }
      maxa = max(maxa, maxs[i][j]);
    }
  }
  cout << "maxs:\n";
  print2DArray(maxs);
  return maxa * maxa;
}

int main() {
  vector<vector<char>> matrix = {{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
  // vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
  // vector<vector<char>> matrix = {{'1','1'},{'1','1'}};  
  cout << maximalSquare(matrix) << "\n";
  cout << maximalSquare2(matrix) << "\n";
  return 0;
}
