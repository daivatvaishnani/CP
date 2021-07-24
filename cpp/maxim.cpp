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
	ll n,k;
	cin >> n >> k;
	ll mn,mx;
	if(k==0 || n==k) {
		mn=0;
		mx=0;
	}	
	else {
		mn=1;
		if(k <= n/3) {
			mx = 2*k;
		}
		else mx = n-k;
	}
	cout << mn << " " << mx << "\n";
	return 0;
}