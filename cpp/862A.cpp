#include <bits/stdc++.h>

using namespace std;

const int maxn = 101;

bool p[maxn];

int main() {
	// freopen("in","r",stdin);
	int n, x, val;
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &val);
		++p[val];
	}
	int ans = 0;
	if(x == 0 && p[0] > 0) {
		printf("1\n");
		return 0;
	}
	for(int i = 0; i < x; ++i) {
		if(p[i] == 0) ++ans;
	}
	if(p[x] > 0) ++ans;
	printf("%d\n", ans);
	return 0;
}