#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000007;
const int mod = 1000000007; 

ll dp[4][N];
bool vis[4][N];

ll compute(int src, int des, ll n) {
	if(n==0) {
		if(src==des) return 1;
		else return 0;
	}
	if(vis[src][n]) return dp[src][n];
	else {
		ll ans = 0;
		for(int i=0; i<4; ++i) {
			if(i!=src) ans = (ans%mod + compute(i,des,n-1)%mod)%mod;
		}
		dp[src][n] = ans;
		vis[src][n] = 1;
		return ans;
	}
}

int main() {
	// freopen("in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N;
	cin >> N;
	cout << compute(3,3,N) << "\n";	
	return 0;
}
