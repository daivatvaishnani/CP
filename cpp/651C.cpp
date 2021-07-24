#include <bits/stdc++.h>

using namespace std;

vector< pair<long long, long long> > P;
unordered_map<long long, long long> MX, MY;

#define X first
#define Y second

int main() {
	freopen("in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,x,y;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> x >> y;
		P.push_back(make_pair(x,y));
		if(MX.find(x) == MX.end()) MX.insert(make_pair(x,1));
		else ++MX[x];
		if(MY.find(y) == MY.end()) MY.insert(make_pair(y,1));
		else ++MY[y];
	}
	sort(P.begin(), P.end());
	long long dupl=0;
	for(int i=1; i<n; ++i) {
		if(P[i].X==P[i-1].X && P[i].Y==P[i-1].Y) ++dupl;
	}
	long long ans=0,ax,ay;
	for(int i=0; i<n; ++i) {
		ax = 0, ay = 0;
		if(MX.find(P[i].X) != MX.end() && MX[P[i].X]>1) {
			ax = MX[P[i].X]-1;
			// --MX[P[i].X];
		}
		if(MY.find(P[i].Y) != MY.end() && MY[P[i].Y]>1) {
			ay = MY[P[i].Y]-1;
			// --MY[P[i].Y];
		}
		ans += ax + ay;
	}
	ans = ans/2 - dupl;
	cout << ans << "\n";
	return 0;
}