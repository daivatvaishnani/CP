#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);
	int a[n];
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	int m = -1;
	for(int i = 0; i < n; ++i) {
		if(k % a[i] == 0 && a[i] > m) {
			m = a[i];
		}
	}
	printf("%d", k / m);	
	return 0;
}