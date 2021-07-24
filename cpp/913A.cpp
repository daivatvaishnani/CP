#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	// freopen("in", "r", stdin), freopen("out", "w", stdout);
	ld n, m;
	scanf("%Lf %Lf", &n, &m);
	if(n > log2(m)) printf("%d\n", (int)m);
	else {
		int a = (int) m, b = (int) n;
		ll c = pow(2, n);
		printf("%lld", a % c);
	}
	return 0;
}