#include <bits/stdc++.h>

using namespace std;

inline void check(double expectedAnswer, double computedAnswer) {
  cout << "expectedAnswer: " << expectedAnswer << "\n";
  cout << "computedAnswer: " << computedAnswer << "\n";
  string correctness = (expectedAnswer == computedAnswer) ? "Accepted" : "Wrong Answer";
  cout << correctness << "\n";
}

int findTotalNumbers(vector<vector<int>> &arrays) {
  int totalNumbers = 0;
  for (auto &array : arrays) {
    totalNumbers += array.size();
  }
  return totalNumbers;
}

int selectLeast(vector<int> &pointers, vector<vector<int> > &arrays) {
  int leastValue = INT_MAX, leastPointer = -1;
  for(int i = 0; i < min(pointers.size(), arrays.size()); ++i) {
    if(pointers[i] < arrays[i].size() && arrays[i][pointers[i]] < leastValue) {
      leastPointer = i;
      leastValue = arrays[i][pointers[i]];
    }
  }
  if(leastPointer != -1) {
    pointers[leastPointer]++;
  }
  return leastValue;
}

vector<int> combineSortedArrays(vector<vector<int> > &arrays) {
  vector<int> result, pointers(arrays.size(), 0);
  int leastValue;
  while((leastValue = selectLeast(pointers, arrays)) != INT_MAX) {
    result.push_back(leastValue);
  }
  return result;
}

double medianOfSortedArrays(vector<vector<int> > &arrays) {
  vector<int> combinedArray = combineSortedArrays(arrays);
  int size = combinedArray.size();
  double median = combinedArray[size / 2];
  if(!(size & 1)) {
    median += combinedArray[size / 2 - 1];
    median /= 2;
  }
  return median;
}

double medianOfTwoSortedArrays(vector<vector<int> > &arrays) {	
  return -1;
}

int main() {
  freopen("out", "w", stdout);
  vector<int> array1 = {1, 2, 3};
  vector<int> array2 = {1, 3, 5, 6};
  vector<vector<int> > arrays = {array1, array2};
  double expectedAnswer = medianOfSortedArrays(arrays);
  double medianOfTwo = medianOfTwoSortedArrays(arrays);
  return 0;
}
