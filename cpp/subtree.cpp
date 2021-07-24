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
const ll N = 2e5+5;
unordered_set<int> G[N];
int main() {
	fio;
	fastio;
	int n,q,a,b,r,s;
	cin >> n >> q;
	rep(i,0,n-2) {
		cin >> a >> b;
		G[a].insert(b);
		rep(i,1,n) {
			if(G[i].find(a)!=G[i].end()) G[i].insert(b);
		}
	}
	rep(i,0,q-1) {
		cin >> r >> s;
		if(G[r].find(s)!=G[r].end()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}