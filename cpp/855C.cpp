#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5+5;
vector<ll> g[N];
int n, m, k, x, a, b;
bool vis[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n - 1; ++i) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);	
	}
	cin >> k >> x;
	
	return 0;
}