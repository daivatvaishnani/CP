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
#define tc(t) int t;cin>>t;while(t--)  
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
const ll mod = 1e9+7;
const ll N = 1e5+5;
ll a[N],b[N],c[N];
int main() {
	fio;
	fastio;
	tc(t) {
		ll n;
		cin >> n;
		rep(i,0,n) cin >> a[i];
		rep(i,1,n) b[i] = (b[i-1]%mod + b[i]%mod)%mod;
		ll ans=1;
		rep(i,0,n-1) c[i] = (b[i]%mod) 
		cout << ans << "\n";   
	}
	return 0;
}