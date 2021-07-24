#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define ll long long
#define ret int 
ll g[237][237];
ll dist[237][237];
ll c,f,x,y,p,ans;
#define V 237
int main() {
	freopen("in","r",stdin); freopen("out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	cin>>c>>f;
	for(ll i=0; i<V; ++i) {
		for(ll j=0; j<=V; ++j) {
			g[i][j]=INF;
		}
	}
	for(ll i=0; i<V; ++i) {
		g[i][i]=0;
	}
	while(f--) {
		cin>>x>>y>>p;
		g[x][y] = p;
		g[y][x] = p;
	}
	for (ll i=0; i<V; ++i) {
        for (ll j=0; j<V; ++j) {
            dist[i][j] = g[i][j];
        }
	}
    for (ll k=1; k<=c; ++k) {
        for (ll i=1; i<=c; ++i) {
            for (ll j=1; j<=c; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    ans=0;
	for(ll i=1; i<=c; ++i) {
		for(ll j=1; j<=c; ++j) {
			if(dist[i][j] == INF) continue;
			if(dist[i][j] > ans)
				ans = dist[i][j];
		}
	}
	cout<<ans<"\n";
	return 0;
}