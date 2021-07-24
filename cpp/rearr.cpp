#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define rep(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define rrep(i,a,b) for(__typeof(b) i=b; i>=a; --i)
#define tc(t) ll t;cin>>t;while(t--)  
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
const ll mod = 1e9+7;
const ll N = 1e5+5;
ll rearrange(ll size, ll l, ll k) {
	for(ld i=pow(2,size); i>=2; i/=2) {
		if(k & 1) {
			l += i/2;
		}
		k = k/2;
	}
	return l+k;
}
int main() {
	fio;
	fastio;
	ll n,k;
	tc(t) {
		cin >> n >> k;
		cout << rearrange(n,0,k) << "\n";
	}
	return 0;
}