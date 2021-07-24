#include <bits/stdc++.h>

using namespace std;

vector< pair<int, pair<int,int> > > Q;
long long A[100001];
const long long M = 1e9+7;

#define t first
#define l second.first
#define r second.second

void Do(pair<int, pair<int, int> > P) {
	for(int i=P.l; i<=P.r; ++i) {
		if(Q[i].t==1) {
			++A[Q[i].l];
			--A[Q[i].r+1];
		}
		else Do(Q[i]);
	}
	return;
}

int main() {	
	freopen("in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T,m,n,ti,li,ri;
	cin >> T;
	while(T--) {
		Q.clear();
		for(int i=0; i<=100000; ++i) A[i]=0;
		cin >> n >> m;
		Q.push_back(make_pair(0,make_pair(0,0))); // Zero Query
		while(m--) {
			cin >> ti >> li >> ri;
			Q.push_back(make_pair(ti,make_pair(li,ri)));
		}
		for(int i=1; i<Q.size(); ++i) {
			if(Q[i].t==1) {
				++A[Q[i].l];
				--A[Q[i].r+1];
			}
			else
				Do(Q[i]); 	
		}
		for(int i=1; i<=n; ++i) 
			A[i] = ((A[i]%M) + (A[i-1]%M))%M;
		for(int i=1; i<=n; ++i)
			cout << A[i] << " ";
		cout << "\n";
	}
}