#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

vector<int> g[N];
int cnt[2];
int n, a, b;

void dfs(int node, int par, bool col) {
	++cnt[col];
	for(int c : g[node]) {
		if(c != par) {
			dfs(c, node, !col);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n - 1; ++i) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0, 0);
	cout << 1LL * cnt[0] * cnt[1] - n + 1;
	return 0;
}