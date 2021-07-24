#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	long long n, a, b;
	cin >> n >> a >> b;
	for(long long i = 0; i*a <= n; ++i) {
		if((n - i*a) % b == 0) {
			cout << "YES\n";
			cout << i << " " << (n - i*a) / b << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}