#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> &vec) {
  for (int i : vec) {
    cout << i << " "; 
  }
  cout << "\n";
}

void printArray(vector<vector<bool>> &arr) {
  for (auto &vec : arr) {
    for(bool b : vec) {
      cout << b << " ";
    }
    cout << "\n";
  }
}

void printString(string &s) {
  for (char c : s) {
    cout << c << " ";
  }
  cout << "\n";
}

/*
  LPS(i) = LPS(i-1) + 1 iff (s[i] == s[i - LPS(i-1)]) 
*/
string longestPalindromicSubstring(string &s) {
  int len = s.length();
  vector<vector<bool>> isPal(len, vector<bool>(len, 0));
  pair<int,int> lps = {0, 0};
  printString(s);
  int add;
  for (int i = 0; i < len; ++i) {
    isPal[i][i] = 1;
  }
  for (int i = 1; i < len; ++i) {
    for (int j = 0; j < i; ++j) {
      isPal[i][j] = s[i] == s[j];
      if (i-1 >= j+1) {
        isPal[i][j] = isPal[i][j] && isPal[i-1][j+1];
      }
      if (isPal[i][j] && i - j > lps.second - lps.first) {
        lps.first = j;
        lps.second = i;
      }
    }
  }
  printArray(isPal);
  return s.substr(lps.first, lps.second - lps.first + 1);
}

int main() {
  string s = "bananas";
  cout << longestPalindromicSubstring(s) << "\n";
  return 0;
}
