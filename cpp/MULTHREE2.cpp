#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		long long K, sum;
		long long d0, d1, curr;
		scanf("%lld %lld %lld", &K, &d0, &d1);
		sum = d0 + d1;
		long long currd = 2;
		if(sum % 5 != 0) {
			while(currd < K) {
				curr = sum % 10;
				if(curr == 8) {
					break;
				}
				sum += curr;
				++currd;
			}
			sum += ((K - currd)/4) * 20;
			if((K - currd) % 4 == 1) sum += 8;
			else if((K - currd) % 4 == 2) sum += 14;
			else if((K - currd) % 4 == 3) sum += 16;
			if(sum % 3 == 0) printf("YES\n");
			else printf("NO\n");
		}
		else {
			while(currd < K) {
				curr = sum % 10;
				if(curr == 0) {
					break;
				}
				sum += curr;
				++currd;
			}
			if(sum % 3 == 0) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}