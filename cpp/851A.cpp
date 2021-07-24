#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in","r",stdin);
	int n,k,t;
	cin >> n >> k >> t;
	if(t >= k && t <= n) cout << k << "\n";
	else if(t < k) cout << t << "\n";
	else cout << max(k-t+n,0) << "\n";
}