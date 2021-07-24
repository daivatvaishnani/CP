#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 66;
int t, n, p, q, x, l, r, ans;
int a[2 * maxn], b[maxn];

inline int mult(int a, int b) {
	return (1LL * a * b) % p;
}

void build() {
	for(int i = n - 1; i > 0; --i) {
		a[i] = mult(a[2 * i], a[2 * i + 1]);
	}
}

int computeans() {
	int res = 1;
	int L = l;
	int R = r + 1;
	for(L += n, R += n; L < R; L >>= 1, R >>= 1) {
		if(L & 1) {
			res = mult(res, a[L++]);
		}
		if(R & 1) {
			res = mult(res, a[--R]);
		}
	}
	return res;
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
			cin >> a[n + i];
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