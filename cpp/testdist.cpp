#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int distance(int cordi1, int cordi2) {
	int dist = cordi1 - cordi2;
	return (dist > 0 ? dist : -dist);
}

int main() {
	cout << distance(6,-3) << endl;

	return 0;
}