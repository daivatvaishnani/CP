#include <bits/stdc++.h>

using namespace std;

vector<int> g[501];
int c[501];
bool found = 0;
int u1, u2;

void visit(int v, int p) {
	if(c[v] == 2) return;
	if(c[v] == 1) {
		u1 = p, u2 = v;
		found = 1;
		return;
	}
	c[v] == 1;
	for(int i : g[v]) visit(i, v);
	c[v] = 2;
	return;
}

int main() {
	freopen("in", "r", stdin);
	int n, m, u, v;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d -> ", i);
		for(int c : g[i]) printf("%d ", c);
		printf("\n");
	}
	for(int i = 1; i <= n; ++i) printf("%d ", c[i]);
	// for(int i = 1; i <= n; ++i) {
	// 	if(c[i] == 0) {
	// 		visit(i, 0);
	// 	}
	// }
	if(!found) printf("Yes\n");
	else {
		g[u1].erase(find(g[u1].begin(), g[u1].end(), u2));
	}
	return 0;
} 