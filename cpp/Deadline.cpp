#include <bits/stdc++.h>

using namespace std;

string solve(double n, double d) {
	if(d <= n) {
		return "YES";
	}
	for(double i = 1; i <= n; ++i) {
		if(i + ceil(d/(i+1)) <= n) {
			return "YES";
		}
	}
	return "NO";
}

int main() {
	freopen("in", "r", stdin), freopen("out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		double n, d;
		cin >> n >> d;
		cout << solve(n, d) << "\n";
	}	
	return 0;
}
