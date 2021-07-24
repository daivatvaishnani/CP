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
#define tc(t) int t;cin>>t;while(t--)  
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
const ll mod = 1e9+7;
const ll N = 1e5+5;
int main() {
	fio;
	fastio;
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int g[26], tot[26];
	rep(i,0,25) g[i]=0, tot[i]=0;
	rep(i,0,s.size()-1)	++g[(int)s[i]-65], ++tot[(int)s[i]-65];
	int open=0;
	bool ok=1;
	rep(i,0,1) {
		cout << (char)(i+65) << " : " << g[i] << " " << tot[i] << "\n"; 
	}
	rep(i,0,s.size()-1)	{
		if((g[(int)s[i]-65]--)==tot[(int)s[i]-65]) ++open;
		if(!g[(int)s[i]-65]) --open; 
		if(open > k) {
			ok=0;
			break;
		}
		rep(i,0,1) {
			cout << (char)(i+65) << " : " << g[i] << " " << tot[i] << "\n" ; 
		}
	}
	if(ok) cout << "NO\n";
	else cout << "YES\n";
	return 0;
}