#include <bits/stdc++.h>

using namespace std;

class Offer {
public:
  int usualp = 0;
  int offerp;
  int quant = INT_MAX;
  vector<int> items;
};

int shoppingOffers(vector<int> &price, vector<vector<int> > &special, vector<int> &needs) {
  int nitems = price.size();
  int noffers = special.size();
  vector<Offer> offers;
  for (int i = 0; i < noffers; ++i) {
    offers[i].offerp = special[i][nitems];
    for (int j = 0; j < nitems; ++j) {
      offers[i].items.push_back(special[i][j]);
      offers[i].usualp += price[j] * special[i][j];
      if (special[i][j] != 0) offers[i].quant = min(offers[i].quant, needs[j] / special[i][j]);
    }
  }
  offers.erase(std::remove_if(
    offers.begin(), offers.end(),
    [](const Offer &offer) {
      return offer.usualp < offer.offerp; 
    }), offers.end());
  
  return -1;
}

int main() {
  vector<int> price = {2,3,4};
  vector<vector<int> > special = {
    {1,1,0,4},
    {2,2,1,9}
  };
  vector<int> needs = {3,2};
  cout << shoppingOffers(price, special, needs) << "\n";
  return 0;
}
