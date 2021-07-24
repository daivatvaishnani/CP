#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 6;

int V[2 * maxn];

int val(int n) {
	int ret = 0;
	string s = to_string(n);
	int m = 1;
	for(int i = 0; i < s.size(); ++i) {
		ret += m * (s[i] - '0');
		if(m == 1) m = -1;
		else m = 1;
	}
	if(ret < 0) ret *= -1;
	return ret;
}

long long ans(int n) {
	long long ret = 0;
	int start = 2;
	for(int i = 1; i <= n; ++i) {
		ret += 1LL * i * V[start++];
	}
	for(int i = n - 1; i >= 1; --i) {
		ret += 1LL * i * V[start++];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	for(int i = 0; i < 2 * maxn; ++i) {
		V[i] = val(i);
	}
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << ans(n) << "\n";
	}
	cout << V[2300003] << "\n";
	return 0;
}