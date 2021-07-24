#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("in", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int cases = 10;
	int maxn = 10;
	int maxval = 101;
	printf("%d\n", cases);
	while(cases--) {
		int n = rand() % maxn + 1;
		int x = rand() % maxval;
		int p = rand() % n + 1;
		int k = rand() % n + 1;
		printf("%d %d %d %d\n", n, x, p, k);
		for(int i = 0; i < n; ++i) {
			printf("%d ", rand() % maxval);
		}
		printf("\n");
	}
	return 0;
}
