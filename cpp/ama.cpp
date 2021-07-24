#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define push_back pb
#define make_pair mp
#define first f
#define second s
#define rep(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define tc(n) int n;cin>>n;while(n--)  
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
const ll mod = 1e9+7;
const ll N = 1e5+5;
vi g[20];
int v[20];
int no[20];
int a,b,n,k;
int main() {
	fio;
	fastio;
	tc(n) {
		rep(i,0,20) g[i].clear();
		cin >> n >> k;
		rep(i,1,n) cin >> v[i];
		rep(i,1,n-1) {
			cin >> a >> b;
			g[a].pb(b);
		}
		rep(i,1,n) {
			rep(j,0,g[i].size()) {
				if()
			}
		}
	}
	return 0;
}