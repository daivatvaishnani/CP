#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 17;

int main() {
	freopen("in","r",stdin);
	int n, x;
	scanf("%d %d", &n, &x);
	if(n == 2 && x == 0) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if(n == 1) {
		printf("%d\n", x);
		return 0;
	}
	else if(n == 2) {
		printf("%d %d\n", 0, x);
		return 0;
	}
	else {
		int y = 0;
		for(int i = 1; i <= n - 3; ++i) {
			printf("%d ", i);
			y ^= i;
		}
		if(y == x) {
			printf("%d %d %d\n", N, 2 * N, N ^ (2* N));
			return 0;
		}
		else {
			printf("%d %d %d\n", 0, N, N ^ x ^ y);
			return 0;
		}
	}
	return 0;
}