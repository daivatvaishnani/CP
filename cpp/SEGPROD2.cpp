#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 6;
int t, n, p, q, x, l, r, ans;
int a[maxn], b[maxn];

void build() {
	for(int i = n)
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n >> p >> q;
		for(int i = 0; i < n; ++i) {
			cin >> a[i + n];
		}
		build();
		for(int i = 0; i < floor(q / 64) + 2; ++i) {
			cin >> b[i];
		}
		x = 0;
		for(int i = 0; i < q; ++i) {
			if(i % 64 == 0) {
				l = (b[i / 64] + x) % n;
				r = (b[i / 64 + 1] + x) % n;
			}
			else {
				l = (l + x) % n;
				r = (r + x) % n;
			}
			if(l > r) {
				swap(l, r);
			}
			ans = computeans();
			x = (ans + 1) % p;
		}
		cout << x << "\n";
	}	
	return 0;
}