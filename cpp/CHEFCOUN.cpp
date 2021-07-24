#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int main() {
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int x = 42949;
		while(x--) {
			printf("%d ", N);
		}
		for(int i = 0; i < n - 42949; ++i) {
			printf("1 ");
		}
		printf("\n");
	}	
	return 0;
}