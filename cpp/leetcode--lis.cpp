#include <bits/stdc++.h>

using namespace std;

typedef vector<unordered_map<int, int> > vmap; 

int go(int i, int prev, vector<int> &arr, vmap &dp) {
  if (i >= arr.size()) return 0;
  if (dp[i].find(prev) != dp[i].end()) return dp[i][prev];
  int ans = 0;
  ans = max(ans, go(i+1, prev, arr, dp));
  if (prev < arr[i]) ans = max(ans, 1+go(i+1, arr[i], arr, dp));
  dp[i][prev] = ans;
  return ans;
}

int lis(vector<int> &arr) {
  int n = arr.size();
  vector<int> LIS(n, 1);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j] < arr[i]) {
        LIS[i] = max(LIS[i], LIS[j]+1);
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, LIS[i]);
  }
  return ans;
}

int main() {
  // vector<int> arr={-1,-2,-3,-4,-5,-6,-7};
  vector<int> arr = {10,9,2,5,3,7,101,18};
  cout << lis(arr) << "\n";
  return 0;
}
