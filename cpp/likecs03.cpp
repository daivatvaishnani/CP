#include <bits/stdc++.h>

using namespace std;

const int maxn = 1048576, maxk = 20;

int present[maxn];
int power[maxk];

int main() {
	// freopen("in","r",stdin);
	int t, n, k, val, ans;
	scanf("%d", &t);
	power[0] = 1;
	for(int i = 1; i < maxk; ++i) {
		power[i] = power[i - 1] << 1;
	}
	while(t--) {
		ans = 0;
		for(int i = 0 ; i < maxn; ++i) {
			present[i] = 0;
		}
		scanf("%d %d",&n, &k);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &val);
			++present[val];
		}
		for(int i = 0; i < k; ++i) {
			if(present[power[i]] <= 0) {
				++ans;
			}
		}
		cout << ans << "\n";
	}	
	return 0;
}