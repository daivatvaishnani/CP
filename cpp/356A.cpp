#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

int p[maxn], r[maxn];

void CREATE() {
	for(int i = 1; i <= n; ++i) {
		p[i] = i;
		r[i] = 0;
	}
}

int FIND(int x) {
	while(p[x] != x) {
		x = p[x];
	}
	return x;
}

void UNION(int x, int y) {
	x = Find(x);
	y = Find(y);
	if(x == y) return;
	if(r[x] > r[y]) {
		p[y] = x;
	}
	else {
		p[x] = y;
	}
	if(r[x] == r[y]) {
		++r[y];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int n, m, l, r, x; 
	cin >> n >> m;
	CREATE();
	for(int i = 0; i < m; ++i) {
		cin >> l >> r >> x;
	}
	return 0;
}