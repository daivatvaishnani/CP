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
const ll N = 5555;
int n,m,k;
vector<string> v;
vector<string> p;
void padd() {
	p.clear();
	string ss,sss;
	int c = v[0].size();
	int r = v.size();
	int cc = c, rr = r;
 	if(c%k!=0) cc = (cc/k+1)*k;
 	if(r%k!=0) rr = (rr/k+1)*k;
 	rep(i,0,cc-c-1) ss=ss+'0';
 	rep(i,0,cc-1) sss=sss+'0';
 	rep(i,0,r-1) p.pb(v[i]+ss);
 	rep(i,0,rr-r-1) p.pb(sss);  
}
int gf(int x, int y) {
	int d=0, l=0;
	rep(i,x,x+k-1) {
		rep(j,y,y+k-1) {
			if(p[i][j]=='1') ++d;
			else ++l;
		}
	}
	if(!d || !l) return 0;
	else return min(d,l);
}
int main() {
	fio;`
	fastio;
	string st;
	cin >> n >> m;
	rep(i,0,n-1) {cin >> st; v.pb(st);}
	int minans=10000; 
	for(k=2; k<=max(n,m); ++k) {		
		padd();
		int pc = p[0].size();
		int pr = p.size();
		int ans=0,temp;
		for(int i=0; i<=pr-k; i+=k)	for(int j=0; j<=pc-k; j+=k)	ans += gf(i,j);
		minans = min(minans,ans);
	}
	cout << minans << "\n";
	return 0;
}