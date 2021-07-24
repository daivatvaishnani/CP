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
	tc(t) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string w;
		if(s[0]=='0') {
			w = "0";
			char fill = '1';
			rep(i,1,n-1) {
				w = w + fill;
				fill = fill=='1' ? '0' : '1';
			}
		}
		else if (s[0]=='1') {
			w = "1";
			char fill = '0';
			rep(i,1,n-1) {
				w = w + fill;
				fill = fill=='1' ? '0' : '1';
			}
		}
		int ans=0;
		// if(n & 1) {
		// 	for(int i=0; i<= n-3; i+=2) {
		// 		if(s[i]!=w[i] || s[i+1]!=w[i+1]) ++ans;
		// 	}
		// 	if(s[n-1]!=w[n-1]) ++ans;
		// }
		// else {
		// 	for(int i=0; i<=n-2; i+=2) {
		// 		if(s[i]!=w[i] || s[i+1]!=w[i+1]) ++ans;
		// 	}
		// }
		rep(i,0,n-1) if(w[i]!=s[i]) ++ans;
 		cout << ans << "\n";
 	}
	return 0;
}	