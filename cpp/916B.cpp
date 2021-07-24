#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 55;

bool prime[maxn];
vector<int> primes;

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	memset(prime, true, sizeof(prime));
	for(int i = 2; i < maxn; ++i) {
		if(prime[i]) {
			primes.push_back(i);
			for(int j = 2*i; j < maxn; j += i) {
				prime[j] = false;
			} 
		}
	}
	primes.insert(primes.begin(), 0);
	long long sp = 0;
	long long maxe = 0;
	for(int i = 0; i < n; ++i) {
		sp += 1LL * (primes[i] - primes[i - 1]);
		maxe = max(maxe, 1LL * (primes[i] - primes[i - 1]));
	}
	cout << sp << " " << sp << "\n";
	for(int u = 1; u < n; ++u) {
		cout << u << " " << u + 1 << " " << primes[u] - primes[u - 1] << "\n";
	}
	m -= n - 1;
	if(m > 0) {
		for(int u = 1; u < n - 1; ++u) {
			cout << u << " " << u + 2 << " " << maxe + 1;
			--m;
			if(m <= 0) break;
		}
	} 
	return 0;
}