#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const long long maxk = 1e5;
const long long inf = 1e18;

long long arr[65][maxk + 1], pre[65][maxk + 1], powk[65][maxk + 1];

long long mul(long long a, long long b) {
	return (a % mod * b % mod) % mod;
}

long long add(long long a, long long b) {
	return (a % mod + b % mod) % mod;
}

long long powmod(long long a, long long b) {
	long long ret = a % mod;
	while(b > 0) {
		if(b & 1) {
			ret = mul(ret, a);
		}
		b >>= 1; 
		ret = mul(ret, ret);
	}
	return ret;
}

long long F(long long k, long long n) {
	long long sum = 0;
	for(long long i = 1; i <= n; ++i) {
		sum = add(sum, i);
		i = mul(i, k);
	}
	cout << "sum for f(" << k << ", " << n << ") : " << sum << "\n";
	return sum;
}

long long calc1(long long k, long long a, long long b) {
	long long S = 0;
	for(long long n = a; n <= b; ++n) {
		S = add(S, F(k, n));
	}
	return S;
}

long long calc2(long long k, long long a, long long b) {
	long long S = 0;
	return S;
}

void precompute() {
	for(int i = 2; i <= maxk; ++i) {
		arr[0][i] = 1;
		for(int j = 1; j < 65 && 1LL * arr[j - 1][i] * i + 1 < inf; ++j) {
			arr[j][i] = 1LL * arr[j - 1][i] * i + 1;
		}
	}
	for(int i = 2; i <= maxk; ++i) {
		powk[0][i] = 1;
		for(int j = 2; j < 65; ++j) {
			powk[j][i] = mul(1LL*i, powk[j - 1][i]);
		}
	}
	for(int i = 2; i <= maxk; ++i) {
		pre[0][i] = powk[1][i] * arr[0][i];
		for(int j = 1; j < 64; ++j) {
			pre[j][i] = add(mul(powk[j + 1][i]), arr)
		}
	}
	for(int i = 0; i < 65; ++i) cout << arr[i][100000] << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("in", "r", stdin), freopen("out", "w", stdout);
	int q;
	cin >> q;
	precompute();
	while(q--) {
		long long k, a, b;
		cin >> k >> a >> b;
		// cout << calc1(k, a, b) << "\n";
		cout << "Ans 1 : " << calc1(k, a, b) << "\n";
		cout << "Ans 2 : " << calc2(k, a, b) << "\n";
	}
	return 0;
}
