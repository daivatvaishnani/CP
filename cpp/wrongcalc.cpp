#include <bits/stdc++.h>

using namespace std;

int wrongSolver(std::vector <unsigned int> a) {
	int n = a.size();
	std::vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	unsigned int mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	cout << mn << "\n";
	return where;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("out", "r", stdin);
	std::vector<unsigned int> v;
	int n = 100000, val;
	while(n--) {
		cin >> val;
		v.push_back(val);
	}
	cout << wrongSolver(v);
	return 0;
}