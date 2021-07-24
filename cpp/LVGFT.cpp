#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

vector<int> g[maxn];
int t[maxn], c[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		for(int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);	
		}
		for(int i = 1; i <= m; ++i) {
			cin >> t[i] >> q[i];
		}

	}	
	return 0;
}