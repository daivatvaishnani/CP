#include <bits/stdc++.h>

using namespace std;

const int maxv = 2e4;

vector<int> g[maxv];
int cc[maxv], dc[maxv], p[maxv];

void color(int v, int c) {
	if(cc[v] != c) {
		cc[v] = c;
		for(int i : g[v]) {
			if(i != p[v]) {
				color(i, c);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		int v;
		cin >> v;
		g[i].push_back(v);
		g[v].push_back(i);
		p[i] = v;
	}
	for(int i = 1; i <= n; ++i) {
		cin >> dc[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(cc[i] != dc[i]) {
			color(i, dc[i]);
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}