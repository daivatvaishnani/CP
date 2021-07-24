#include <bits/stdc++.h>

using namespace std;

void print_list(list<int> &arr) {
  for (auto it : arr) {
    printf("%d ", it);
  }
  printf("\n");
} 

int main() {
  list<int> arr = {1, 2, 3, 4, 5};
  auto it = find(arr.begin(), arr.end(), 6);
  arr.splice(arr.begin(), arr, it);
  print_list(arr);
}
