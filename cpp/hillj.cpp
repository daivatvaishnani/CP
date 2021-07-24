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
ll a[N];
ll n,q,l,r,x,i,k,type,ans;
ll ifdo() {
	ll ans=i,tans=i;
	while(k) {
		while(a[ans]>=a[tans] && tans<=n) ++tans;
		if(tans-ans>100 || tans>n) return ans;
		else {
			--k;
			ans = tans;
		}
	}
	return ans;
}
void doelse() {
	rep(j,l,r) a[j]+=x;
}
int main() {
	fio;
	fastio;
	cin >> n >> q;
	rep(j,1,n) cin >> a[j];
	while(q--) {
		cin >> type;
		if(type==1) {
			cin >> i >> k;
			ans = ifdo();
			cout << ans << "\n";
		}
		else {
			cin >> l >> r >> x;
			doelse();
		}
	}
	return 0;
}