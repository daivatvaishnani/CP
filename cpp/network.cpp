#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int main() {
	cin >> n >> k;
	ans = (n-1)/k;
	ans = (n-1)%k >= 2 ? 2*ans +2 : 2*ans +(n-1)%k;
	cout << ans << "\n";
	for(int i=2; i<=k+1; ++i)	cout << "1 " << i << "\n";
	for(int j=2, i=k+2; i<=n;) {
		cout << j++ << " " << i++ << "\n";
	}
}