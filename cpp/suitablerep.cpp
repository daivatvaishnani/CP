#include <bits/stdc++.h>
using namespace std;

#define v first
#define list second 

int n, m, a, b;

class cmp {
public:
	bool operator() (pair<int, vector<int> > p1, pair<int, vector<int> > p2) {
		return p1.list.size() < p2.list.size();
	}
};

int main() {
	cin >> n >> m;
	vector<int> g[n+1];
	vector<pair<int, vector<int> > > G;
	int label[n+1];
	for(int i=0; i<=n; ++i) label[i]=-1;
	while(m--) {
		cin >> a >> b;
		g[a].push_back(b); 
	}
	for(int i=1; i<=n; ++i) {
		G.push_back(make_pair(i, g[i]));
	}
	sort(G.begin(), G.end(), cmp());
	for(int i=0; i<n; ++i) {
		if(G[i].list.size() == 0) label[G[i].v] = n;
		else {
			
		}
	} 
}