#include <bits/stdc++.h>

using namespace std;

long long n;
const long long maxn = 50001;
const long long inf = 1e9;
vector<long long> v;
long long arr[maxn], prexor[maxn];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// freopen("in", "r", stdin);
	cin >> n;
	int k;
	cin >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	prexor[0] = arr[0];
	for(int i = 1; i < n; ++i) {
		prexor[i] = prexor[i - 1] ^ arr[i];
	}
	for(int l = 0; l < n; ++l) {
		for(int r = l; r < n; ++r) {
			long long val, minm = arr[l], xorr;
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