#include <bits/stdc++.h>

using namespace std;

vector<int> c[1005];
int lc[1005], pr[1005];
bool leaf[1005];

void go(int v) {
	if(leaf[v]) {
		++lc[pr[v]];
		lc[v] = 0;
		return;
	}
	for(int i : c[v]) go(i);
}

int main() {
	// freopen("in", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int p;
		scanf("%d", &p);
		pr[i + 1] = p;
		c[p].push_back(i + 1);
	}
	for(int i = 1; i <= n; ++i) {
		if((int)c[i].size() == 0) leaf[i]=1;
	}
	go(1);
	bool ok = 1;
	for(int i = 1 ; i <= n; ++i) {
		if(leaf[i] || lc[i] >= 3) continue;
		ok = 0;
		break;
	}
	if(!ok) printf("No\n");
	else printf("Yes\n");
	return 0;
}