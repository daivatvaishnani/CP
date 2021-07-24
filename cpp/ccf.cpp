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
const ll N = 100;
int t,n,ans,tm,val;
bool ach=0;
string st;
int a[100];
int main() {
	fio;
	fastio;
	cin >> t;
	cin.ignore();
	while(t--) {
		n=0;
		getline(cin,st);
		stringstream ss;
		ss << st;
		n = 0;
		while(ss >> a[n]) ++n;
 		ach = 0;
		ans = 0;
		n-=1;
		rep(i,0,n) {
			if(a[i]==n && !ach) {
				ach=1;
				continue;
			}
			else ans = max(ans,a[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}