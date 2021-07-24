#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5, M = 1e9+7;

int type[N], l[N], r[N], c[N], a[N];
int t, n, m;

int main() {
	freopen("in", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for(int i=1; i<=m; ++i) {
			scanf("%d %d %d", type+i, l+i, r+i);
		}
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		c[m+1] = 1;
		for(int i = m; i >= 1; --i) {
			c[i] = (c[i] + c[i+1]) % M;
			if(type[i] == 1) {
				a[l[i]] = (a[l[i]] + c[i]) % M;
				a[r[i] + 1] = (a[r[i] + 1] - c[i] + M) % M;
			}
			else {
				c[r[i]] = (c[r[i]] + c[i]) % M;
				c[l[i] - 1] = (c[l[i] - 1] - c[i] + M) % M;
			}
		}
		for(int i = 1; i <= n; ++i) {
			a[i] = (a[i] + a[i - 1]) % M;
			printf("%d%c", a[i], (i!=n ? ' ' : '\n'));
		}
	}
	return 0;
}