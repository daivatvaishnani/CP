#include <bits/stdc++.h>

using namespace std;

long long n;
const long long maxn = 50001;
const long long inf = 1e9;
vector<long long> v;
long long arr[maxn], prexor[maxn], t[2*maxn];

long long query(long long l, long long r) {
	long long res = inf;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = min(res, t[l++]);
		if (r&1) res = min(res, t[--r]);
	}
	return res;
}

void build(long long n) {
	for (int i = n - 1; i >= 1; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// freopen("in", "r", stdin);
	cin >> n;
	int k;
	cin >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	prexor[0] = arr[0];
	for(int i = 1; i < n; ++i) {
		prexor[i] = prexor[i - 1] ^ arr[i];
	}
	for(int i = 0; i < n; ++i) {
		t[i + n] = arr[i];
	}
	build(n);
	int sum = 0;
	for(int l = 0; l < n; ++l) {
		for(int r = l; r < n; ++r) {
			++sum;
			long long val, minm = query(l, r + 1), xorr;
			if(l == 0) {
				xorr = prexor[r];
			}
			else {
				xorr = prexor[r]^prexor[l - 1];
			}
			val = minm * xorr;
			v.push_back(val);
		}
	}
	sort(v.begin(), v.end());
	cout << v[k - 1] << "\n";
	return 0;
}