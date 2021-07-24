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
const ll N = 105;
ll n, k, ans;
ll a[N], b[N];
ll m=8;
int main() {
	fio;
	fastio;
	cin >> n >> k;
	for(int i=0; i<N; ++i) {
		a[i]=0, b[i]=0;	
	}
	rep(i,1,n) {
		cin >> a[i];
	}
	rep(i,1,n) {
		b[i] += b[i-1] + min(m, a[i]);
		a[i+1] += a[i] - min(m, a[i]);
	}
	if(b[n]<k) cout << "-1";
	else cout << (lower_bound(b+1,b+n+1,k)-b);
	return 0;
}