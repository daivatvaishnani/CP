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
ll n,d,sum,k,ans,diff;
ld kd;
ll a[N],ta[N];
void reset() {
	for(int i=0;i<N;++i) a[i]=0, ta[i]=0;
	sum = 0;
	ans = 0;
}
bool ok() {
	rep(i,0,n-1) {
		if(a[i]!=k) return 0;
	}
	return 1;
}
ll move(ll i) {
	ll j=i+d;
	if(a[i]<k) {
		ll temp = k-a[i];
		a[j] -= temp;
		a[i] = k;
		return temp;
	}
	else if(a[i]>k) {
		ll temp = a[i]-k;
		a[j] += temp;
		a[i] = k;
		return temp;
	}
	else return 0;
}
int main() {
	fio;
	fastio;
	tc(t) {
		reset();
		cin >> n >> d;
		rep(i,0,n-1) {
			cin >> a[i];
			sum += a[i];
		}
		kd = sum/(n+.0);
		if((int)kd < kd) {
			cout << "-1\n";
			continue;
		}
		k = (int) kd;
		rep(i,0,n-d-1) {
			ans += move(i);
		}
		if(ok()) cout << ans << "\n";
		else cout << "-1\n";
	}
	return 0;
}