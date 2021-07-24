#include <bits/stdc++.h>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
  return {};
}

int main() {
  vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
  int numCourses = 4;
  vector<int> order = findOrder(numCourses, prerequisites); 
}
