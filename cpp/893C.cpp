#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int p[maxn], r[maxn], g[maxn];
set<int> S[maxn];

int find(int i) {
	while(p[i] != i) i = p[i];
	return i;
}

void mf(int i, int j) {
	i = find(i);
	j = find(j);
	if(i == j) {
		return;
	}
	if(r[i] > r[j]) {
		p[j] = i;
	}
	else {
		p[i] = j;
	}
	if(r[i] == r[j]) {
		++r[j];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> g[i];
		p[i] = i;
		r[i] = 0;
	}
	int f1, f2;
	for(int i = 1; i <= m; ++i) {
		cin >> f1 >> f2;
		mf(f1, f2);
	}
	for(int i = 1; i <= n; ++i) {
		S[find(i)].insert(g[i]);		
	}
	long long amt = 0; 
	for(int i = 1; i <= n; ++i) {
		if(!S[i].empty()) {
			amt += 1LL*(*(S[i].begin()));
		}
	}
	cout << amt << "\n";
	return 0;
}