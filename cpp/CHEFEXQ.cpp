#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
long long a[maxn], b[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	long long n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	while(q--) {
		long long type, x, y;
		cin >> type >> x >> y;
		if(type == 1) {
			a[x] = y;
		}
		else if(type == 2) {
			long long ans = 0;
			b[1] = a[1];
			for(int i = 2; i <= x; ++i) {
				b[i] = b[i - 1] ^ a[i];
			}
			for(int i = 1; i <= x; ++i) {
				if(b[i] == y) {
					++ans;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}