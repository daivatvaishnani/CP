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
int main() {
	// fio;
	fastio;
	ll n,l,r;
	cin >> n;
	vector<pair<ll,ll> > Vec;
	rep(i,0,n-1) {
		cin >> l >> r;
		Vec.pb(mp(l,r));
	}
	sort(Vec.begin(), Vec.end());
	ll o=-1,t=-1;
	rep(i,0,n-1) {
		if(Vec[i].f > o) o=Vec[i].s;
		else if(Vec[i].f > t) t=Vec[i].s;
		else {
			cout << "NO\n";
			return 0;
		} 
	}
	cout << "YES\n";
	return 0;
}