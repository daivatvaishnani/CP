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
	fio;
	fastio;
	ll t,ans;
	ll p[26],m[26];
	string S;
	cin >> t;
	while(t--) {
		rep(i,0,25) cin >> p[i];
		rep(i,0,25) m[i]=0;
		cin >> S;
		rep(i,0,S.size()-1) {
			++m[(int)(S[i]-97)];
		}
		ans=0;
		rep(i,0,25) {
			if(m[i]==0) {
				ans+=p[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}