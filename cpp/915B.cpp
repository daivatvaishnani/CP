#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in", "r", stdin);
	int n, i, l, r;
	scanf("%d %d %d %d", &n, &i, &l, &r);
	int ans = 0;
	if(i < l) {
		ans += l - i + 1;
		if(r + 1 <= n) ans += r - l + 1;
	}
	else if(i >= l && i <= r) {
		if(i - l < r - i) {
			if(l - 1 >= 1) {
				ans += i - l + 1;
				if(r + 1 <= n) ans += r - l + 1;
			}
			else if(r + 1 <= n) ans += r - i + 1;
		}
		else {
			if(r + 1 <= n) {
				ans += r - i + 1;
				if(l - 1 >= 1) ans += r - l + 1;
			}
			else if(l - 1 >= 1) ans += i - l + 1;
		}
	}
	else {
		ans += i - r + 1;
		if(l - 1 >= 1) ans += r - l + 1;
	}
	printf("%d\n", ans);
	return 0;
}