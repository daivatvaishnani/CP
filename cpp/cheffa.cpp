#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
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
typedef unordered_set<string> uss;
uss ans, data;
vll v;
ll t,n,val;
inline void printv(vi vec) {
	rep(i,0,v.size()-1) cout << v[i] << " ";
	cout << "\n";
}
inline void reset() {
	v.clear(), ans.clear(), data.clear();
}
int main() {
	fio;
	fastio;
	cin >> t;
	while(t--) {
		reset();
		cin >> n;
		rep(i,0,n-1) {
			cin >> val;
			v.pb(val)
		}
	}
	return 0;
}