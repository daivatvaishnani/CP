#include <bits/stdc++.h>

using namespace std;

const int MAXX = 3e5+5;
int T[MAXX],C[MAXX],TL[MAXX];

class Cmp {
public:
	bool operator()(pair<int,int> p1, pair<int,int> p2) {
		if(p1.second != p2.second)
			return p1.second < p2.second;
		else return p1.first < p2.first;
	}
};

int main() {
	// freopen("in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	for(int i=1; i<=N; ++i) cin >> C[i];
	for(int i=1; i<=N; ++i) T[i]=i;
	priority_queue< pair<int,int>, vector<pair<int,int> >, Cmp> Q;
	for(int i=1; i<=K+1; ++i) Q.push(make_pair(T[i],C[i]));
	int time = K+1;
	int flights_left=0;
	long long cost=0;
	int enter = K+2;
	while(flights_left<N) {
		cost += 1LL*(time - T[Q.top().first])*(Q.top().second);
		TL[Q.top().first]=time;
		++time, ++flights_left;
		Q.pop();
		if(enter<=N)
			Q.push(make_pair(T[enter],C[enter]));
		++enter;
	}
	cout << cost << "\n";
	for(int i=1; i<=N; ++i) cout << TL[i] << " ";
}