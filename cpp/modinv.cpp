#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
long long inv[maxn];

void fill() {
	inv[1] = 1;
	for(int i = 2; i < maxn; ++i) {
		inv[i] = (mod - (mod/i) * inv[mod % i] % mod) % mod;
		// inv[i] = (-(mod/i) * inv[mod % i]) % mod + mod;	
	}
}

int main() {
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill();
	for(int i = 1; i <= 100; ++i) {
		cout << i << ":" << inv[i] << ":" << 1LL*i*inv[i] % mod << "\n";
	}
	return 0;
}