#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6;
int l[maxn];
int dead[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> l[i];
	}
	for(int i = n - 1; i >= 0; --i) {
		int mark = i - l[i];
		if(mark < 0) mark = 0;
		++dead[mark];
		--dead[i];
	}
	for(int i = 1; i < n; ++i) {
		dead[i] += dead[i - 1];
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(dead[i] == 0) ++ans;
	}
	cout << ans << "\n";
	return 0;
}