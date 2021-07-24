#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--) {
		long long k, sum;
		long long d0, d1, dg;
		scanf("%lld %lld %lld", &k, &d0, &d1);
		sum = d0 + d1;
		long long d = 2;
		if(sum % 5 == 0) {
			while(d < k) {
				dg = sum % 10;
				if(dg == 0) {
					break;
				}
				sum += dg;
				++d;
			}
			if(sum % 3 == 0) printf("YES\n");
			else printf("NO\n");
		}
		else {
			while(d < k) {
				dg = sum % 10;
				if(dg == 8) {
					break;
				}
				sum += dg;
				++d;
			}
			sum += ((k - d)/4) * 20;
			if((k - d) % 4 == 1) sum += 8;
			else if((k - d) % 4 == 2) sum += 14;
			else if((k - d) % 4 == 3) sum += 16;
			if(sum % 3 == 0) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}