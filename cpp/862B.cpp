#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

vector<int> g[maxn];
bool vis[maxn], c[maxn];
int n, a, b;
int cnt[2];
long long ans;

void dfs(int idx) {
	vis[idx] = 1;
	for(int i = 0; i < g[idx].size(); ++i) {
		if(vis[g[idx][i]] == 0) {
			c[g[idx][i]] = c[idx] ^ 1;
			++cnt[c[g[idx][i]]];
			dfs(g[idx][i]);
		}
	}
}

int main() {
	freopen("in","r",stdin);
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	c[1] = 0;
	cnt[0] = 1, cnt[1] = 0;
	for(int idx = 1; idx <= n; ++idx) {
		if(vis[idx] == 0) {
			dfs(idx);
		}
	}
	ans = 1LL * cnt[0] * cnt[1] - n + 1;
	printf("%lld\n", ans);
	return 0;
}