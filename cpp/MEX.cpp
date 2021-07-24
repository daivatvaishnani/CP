#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, k, val, ans;
bool s[2*N];
		
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n >> k;
		memset(s, false, sizeof(s));
		for(int i = 0; i < n; ++i) {
			cin >> val;
			s[val] = true;
		}
		ans = 0;
		while(k >= 0) {
			if(!s[ans]) {
				--k;
			}
			++ans;
		}
		cout << ans - 1 << "\n";
	} 	
	return 0;
}