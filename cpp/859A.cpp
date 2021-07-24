#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	int k, val, maxv=0;
	cin >> k;
	for(int i=0; i<k; ++i) {
		cin >> val;
		maxv = max(maxv, val);
	}
	cout << max(0, maxv-25) << "\n";
	return 0;
}