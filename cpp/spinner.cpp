#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define push_back pb
// #define make_pair mp
#define first f
#define second s
#define rep(i,a,b) for(auto i=a; i<=b; ++i)
#define tc(t) int t;cin>>t;while(t--)  
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
const ll mod = 1e9+7;
const ll N = 1e5+5;
map<char,int> m;
int main() {
	fio;
	fastio;
	m.insert(make_pair('v',0));
	m.insert(make_pair('<',1));
	m.insert(make_pair('^',2));
	m.insert(make_pair('>',3));
	char a,b;
	ll rot;
	cin >> a >> b;
	cin >> rot;
	ll res1,res2;
	if(m[b]-m[a] > 0) {
		res1 = (m[b]-m[a])%3;
		if(res1==0) res1=1;
		res2 = 4-res1;
		cout << res1 << " " << res2 << "\n";
		if(res1==res2) cout << "undefined\n";
		else {
			if(b%res1==0) cout << "cw\n";
			else cout << "ccw\n"; 
		}
	}
	else {
		res1 = (m[a]-m[b]%3);
		if(res1==0) res1=1;
		res2 = 4-res1;
		if(res1==res2) cout << "undefined\n";
		else {
			if(b%res1==0) cout << "ccw\n";
			else cout << "cw\n";
		}
	}
	return 0;
}