#include <bits/stdc++.h>

using namespace std;

int main() {
  int g, s;
  scanf("%d %d", &s, &g);
  if(g < s) swap(g, s);
  printf("%d %d\n", s, g);
  return 0;
}
