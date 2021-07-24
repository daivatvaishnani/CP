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
#define repstl(i,v) for(auto i:v)
#define tc(t) int t;cin>>t;while(t--)  
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
#define cc(c) ((int)c-97)
const ll mod = 1e9+7;
const ll N = 1e5+5;
int ss[26], tt[26], ww[26];
string s, t, w;
int szs, szt, szw;
void reset() {
	rep(i,0,25) ss[i]=0, tt[i]=0, ww[i]=0;
}
int main() {
	fio;
	fastio;
	tc(n) {
		reset();
		cin >> s >> t;
		szs = s.size();
		szt = t.size();
		szw = w.size();
		rep(i,0,szs-1) ++ss[cc(s[i])];
		rep(i,0,szt-1) ++tt[cc(t[i])];
		// show();
		int flag=0;
		int cnt1=0, cnt2=0;
		rep(i,0,25) if(tt[i]) ++cnt1;
		rep(i,0,25) if(tt[i] && ss[i]) ++cnt2;
		if(cnt1==cnt2) {
			cnt1=0;
			rep(i,0,25) if(ss[i] && !tt[i]) ++cnt1;
			if(cnt1 > 0) {cout << "A\n"; continue;}
		}
		flag=0;
		rep(i,0,25) {
			if(ss[i]>1 && !tt[i]) {flag=1; break;}
		}
		if(flag==1) cout << "A\n";
		else cout << "B\n";
	}
	return 0;
}