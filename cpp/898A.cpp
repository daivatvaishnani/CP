#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n, u;
	cin >> n;
	u = n % 10;
	if(min(10 - u, u) == u) {
		cout << n - u << "\n";
	}
	else {
		cout << n + 10 - u << "\n";
	}
	return 0;
}