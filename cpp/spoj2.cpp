#include <bits/stdc++.h>

using namespace std;

const int maxn = sqrt(1e9)+1;
bool prime[maxn+1];

long long ans = 0;

void simplesieve() {
	memset(prime,true,sizeof(prime));
	for(int i=2; i*i<=maxn; ++i) if(prime[i] == true) for(int j=i*i; j<=maxn; j+=i) prime[j] = false, ++ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("in","r",stdin); freopen("out", "w", stdout);
	// int t;
	// cin >> t;
	// simplesieve();
	simplesieve();
	cout << ans;
	// while(t--) {

	// }
	return 0;
}