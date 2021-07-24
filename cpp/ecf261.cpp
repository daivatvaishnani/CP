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
int n,ans,cur;
string st,tmp;
int main() {
	// fio;
	fastio;
	cin >> n;
	cin.ignore();
	getline(cin,st);
	stringstream ss;
	ss << st;
	ans=0;
	while(ss >> tmp) {
		cur=0;
		rep(i,0,tmp.size()) {
			if((int)tmp[i]<=90 && (int)tmp[i]>=65) ++cur;
		}
		ans = max(ans, cur);
	}
	cout << ans << "\n";
	return 0;
}