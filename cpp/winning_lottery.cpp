#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6; 

string arrs[maxn];
int arr[maxn], a[10], pow2[11], freq[1024];
unordered_map <string, int> m;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("in", "r", stdin), freopen("out", "w", stdout);
	int n;
	cin >> n;
	pow2[0] = 1;
	for(int i = 1; i < 11; ++i) {
		pow2[i] = pow2[i - 1] << 1;
	}
	// cout << "\n";
	for(int i = 0; i < n; ++i) {
		cin >> arrs[i];
		if(m.count(arrs[i])) {
			++m[arrs[i]];
		}
		else {
			m.insert(make_pair(arrs[i],1));
		}
		// cout << s << "\n";
		memset(a, 0, sizeof(a));
		for(char c : arrs[i]) {
			++a[c - '0'];
		}
		for(int j = 0; j < 10; ++j) {
			// cout << a[j] << " ";
			if(a[j] > 0) {
				// cout << "1 ";
				arr[i] += pow2[(9 - j)];
			}
			// else cout << "0 ";
		}
		// cout << "\n";
	}
	// for(int i = 0; i < n; ++i) {
	// 	cout << arr[i] << "\n";
	// }
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		++freq[arr[i]];
	}
	for(int i = 0; i < 1024; ++i) {
		for(int j = i; j < 1024; ++j) {
			if(freq[i] > 0 && freq[j] > 0 && (i | j) == 1023) {
				// cout << "i : " << i << "\tj ; " << j << " freq[i] : " << freq[i] << " freq[j] : " << freq[j] << "\n";
				if(i == j) {
					ans += (freq[i] * (freq[i] - 1)) / 2;
				}
				else {
					ans += freq[i] * freq[j];
				}
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		if(m.count(arrs[i])) {
			ans -= (m[arrs[i]] * (m[arrs[i]] - 1)) / 2;
		}
	}
	// for(int i = 0; i < n - 1; ++i) {
	// 	for(int j = i + 1; j < n; ++j) {
	// 		if(((arr[i] | arr[j]) == pow2[10] - 1)) {
	// 			++ans;
	// 		}
	// 	}
	// }
	cout << ans << "\n";
	return 0;
}

/*
5
129300455 
5559948277
012334556 
56789
123456879
*/