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
ll a[N], val[N];
ll odd, even;
int main() {
	fastio;
	ll n;
	cin >> n;
	vi v;
	repstl(i,v) {

	}
	rep(i,1,n) {
		cin >> a[i];
		if(a[i] & 1) {
			odd = even = a[i]/2 + 1;
		}
		else {
			odd = a[i]/2;
			even = odd + 1;  
		}
		odd = ((odd%mod*(odd-1)%mod)%mod + odd%mod)%mod;
		even = ((even%mod*(even-1)%mod)%mod + even%mod)%mod;
		a[i] = odd + even;
	}
	ll ans = 1;
	rep(i,1,n) ans = (ans%mod*a[i]%mod)%mod;
	cout << ans << "\n";
	return 0;
}