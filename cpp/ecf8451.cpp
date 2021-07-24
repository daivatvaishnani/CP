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
vector<int> V;
int n,val;
int main() {
	// fio;
	fastio;
	cin >> n;
	rep(i,0,2*n-1) {
		cin >> val;
		V.pb(val);
	}
	sort(V.begin(), V.end());
	int szV = V.size();
	if(V[n-1] >= V[n]) cout << "NO\n";
	else cout << "YES\n";	
	return 0;
}   