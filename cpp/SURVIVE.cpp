#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in", "r", stdin);
	int T, N, K, S;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &N, &K, &S);
		int possible = 0, needed = K * S;
		for(int day = 1; day <= S; ++day) {
			if(day % 7 != 0) possible += N;
		}
		if(possible >= needed) {
			int ans = needed / N;
			if(needed % N != 0) ++ans;
			printf("%d\n", ans);
		}
		else {
			printf("-1\n");
		}
	}
	return 0;
}
