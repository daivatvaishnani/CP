#include <bits/stdc++.h>
#include "printutils.h"

using namespace std;

bool wordBreak(string s, vector<string> &wordDict) {
  int len = s.length();  
  unordered_set<string> dict(wordDict.begin(), wordDict.end());
  vector<vector<bool>> word(len, vector<bool>(len, 0));
  string sub;
  printArray(wordDict);
  cout << s << "\n";
  for (int i = 0; i < len; ++i) {
    sub = "";
    for (int j = i; j < len; ++j) {
      sub += s[j];
      if (dict.find(sub) != dict.end()) {
        word[i][j] = 1;
      }
    }
  }
  printSegments(word, true);
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < i; ++j) {
      word[0][i] = word[0][i] || (word[0][j] && word[j+1][i]);
    }
  }
  cout << "after calc:\n";
  printSegments(word, true);
  return word[0][len-1];  
}

int main() {
  string s = "applepenapple";
  vector<string> wordDict = {"apple", "pen"};
  cout << wordBreak(s, wordDict) << "\n";
  return 0;
}
