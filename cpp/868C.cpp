#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int a[maxn][4];
int cnt[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < k; ++j) {
			cin >> a[i][j];
			if(a[i][j] == 1) {
				++cnt[j];
			}
		}
	}
	for(int i = 0)
	return 0;
}