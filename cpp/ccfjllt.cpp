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
#define repstl(i,v) for(auto i:v)
#define tc(n) int n;cin>>n;while(n--)  
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
const ll mod = 1e9+7;
const ll N = 1e5+5;
int temp,ans,val,n;
int main() {
	fio;
	string tt;
	getline(cin, tt);
	int t = tt[0] - '0';
	cout << t << "\n"; 
	string st;
	while(t--) {
		getline(cin,st);
		fflush(stdin);
		cout << st << "\n";
		n=0;
		int i=0;
		temp = n+1;
		ans=0;
		while(temp--) {
			cin >> val;
			if(val==n) continue;
			else ans=max(ans,val);
		}
		// cout << ans << "\n";
	}
	return 0;
}