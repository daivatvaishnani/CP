#include <bits/stdc++.h>

using namespace std;

class Tester {
  class Node {
    int key, val;
    Node *next, *prev;
  };

public:
  Node *front, *back;
  
  Tester(): front(NULL), back(NULL) {}

};

int main() {
  Tester tester;
  if (!tester.front) {
    cout << "front is null\n";
  }
  if (!tester.back) {
    cout << "back is null\n";
  }
}
