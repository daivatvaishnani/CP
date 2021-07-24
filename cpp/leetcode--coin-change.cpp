#include <bits/stdc++.h>

using namespace std;

int getncoin(int i, vector<int> &ncoins) {
  if (i >= 0 && i < ncoins.size()) {
    return ncoins[i];
  }
  return -1;
}

int coinChange(vector<int> &coins, int amount) {
  vector<int> ncoins(amount+1, -1);
  for (int i : coins) {
    if (i >= 0 && i < ncoins.size()) {
      ncoins[i] = 1;
    }    
  }
  int ncoin;
  for (int i = 0; i <= amount; ++i) {
    if (i == 0) {
      ncoins[i] = 0;
      continue;
    }
    for (int j : coins) {
      ncoin = getncoin(i-j, ncoins);
      if (ncoin != -1) {
        if (ncoins[i] == -1) {
          ncoins[i] = ncoin + 1;
        } else {
          ncoins[i] = min(ncoins[i], ncoin + 1);
        }
      }
    }
  }
  return getncoin(amount, ncoins); 
}

int main() {
  vector<int> coins = {1};
  int amount = 0;
  cout << coinChange(coins, amount) << "\n"; 
  return 0;
}
