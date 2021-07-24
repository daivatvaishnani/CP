#include <bits/stdc++.h>

using namespace std;

const long long maxn = 50001;
const long long inf = 1e9;

long long a[maxn], d[maxn];
vector<long long> v;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// freopen("in", "r", stdin);
	long long n;
	cin >> n;
	int k;
	cin >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	d[0] = a[0];
	for(int i = 1; i < n; ++i) {
		d[i] = d[i - 1] ^ a[i];
	}
	for(int l = 0; l < n; ++l) {
		for(int r = l; r < n; ++r) {
			long long mini = a[l], xorr;
			if(l == 0) {
				xorr = d[r];
			}
			else {
				xorr = d[r]^d[l - 1];
			}
			v.push_back(mini * xorr);
		}
	}
	sort(v.begin(), v.end());
	cout << v[k - 1] << "\n";
	return 0;
}