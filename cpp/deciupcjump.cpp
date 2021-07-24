#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> v;
	v.clear();
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(), v.end());
	a = v[0];
	b = v[1];
	c = v[2];
	cout << abs(c - b - a) << "\n";
	return 0;
}