#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int a[maxn][4];
int q[maxn];
int t, n, qr;

long long doo(int idx) {
	int qi = q[idx];
	long long ans = 1LL*a[0][0] + 1LL*a[0][1]*qi + 1LL*a[0][2]*qi*qi + 1LL*a[0][3]*qi*qi*qi;
	for(int i = 1; i < n; ++i) {
		ans = min(ans, 1LL*a[i][0] + 1LL*a[i][1]*qi + 1LL*a[i][2]*qi*qi + 1LL*a[i][3]*qi*qi*qi);
	} 
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
		}
		cin >> qr;
		for(int i = 0; i < qr; ++i) {
			cin >> q[i];
		}
		for(int i = 0; i < qr; ++i) {
			cout << doo(i) << "\n";
		}
	}
	return 0;
}

/*

*/