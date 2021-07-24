#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define rep(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define rrep(i,a,b) for(__typeof(b) i=b; i>=a; --i)
#define tc(t) int t;cin>>t;while(t--)  
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
const ll mod = 1e9+7;
const ll N = 1e5+5;
ll F[222];
ll T,n,q,t,x,y,sum;
ll pf() {
	ll res=0;
	for(int i=x; i<=n; i+=x)
		res = (res%mod + (F[i]%mod)*(F[i]%mod)%mod)%mod;
	return res;
}
int main() {
	fio;
	fastio;
	cin >> T;
	while(T--) {
		for(int i=0; i<101; ++i) F[i]=0;
		cin >> n >> q;
		for(int i=1; i<=n; ++i) cin >> F[i];
		while(q--) {
			cin >> t;
			if(t==1) {
				cin >> x;
				cout << pf() << "\n";
			}
			else {
				cin >> x >> y;
				F[x] = y;
			}
		}
	}
	return 0;
}