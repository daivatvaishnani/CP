#include <bits/stdc++.h>

using namespace std;

void test_case(int case_no) {
  int n, no;
	cin >> n;
	cout << "CASE #" << case_no << ":\n";
	cout << "arr: ";
	for(int i = 0; i < n; ++i) {
		cin >> no;
		cout << no << " ";
	}
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		test_case(i);
	}
}
