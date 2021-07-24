#include <bits/stdc++.h>

using namespace std;

#define cont_size first
#define cont_address second

vector< pair<int, int> > holes, allocated;

pair<int, int> find_fit(int req_size, bool m) {
  pair<int, int> fit;
  if(!m) {
    //best_fit
  }
  else {
    //worst_fit
  }
  return fit;
}

void best_fit(int req_size) {
  pair<int, int> fit = find_fit(req_size, 0);
  return;
}

void worst_fit(int req_size) {
  pair<int, int> fit = find_fit(req_size, 1);
  return;
}

void process(int req_size) {
  best_fit(req_size);
  worst_fit(req_size);
  return;
}

int main() {
  int mem_size, req_no, req_size;
  scanf("%d", &mem_size);
  holes.clear(), allocated.clear();
  holes.push_back(make_pair(mem_size, 0));
  while(scanf("%d", &req_no)) {
    scanf("%d", &req_size);
    process(req_size);
  }
  return 0;
}
