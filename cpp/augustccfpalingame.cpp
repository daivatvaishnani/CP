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
void show() {
	cout << "---------------------------------\n";
	rep(i,0,s.size()-1) cout<<s[i]<<" "<<ss[cc(s[i])]<<"\n";
		cout << "\n";
		rep(i,0,t.size()-1) cout<<t[i]<<" "<<tt[cc(t[i])]<<"\n";
		cout << "---------------------------------\n";
}
int main() {
	fio;
	fastio;
	tc(n) {
		reset();
		cin >> s >> t;
		szs = s.size();
		szt = t.size();
		rep(i,0,szs-1) ++ss[cc(s[i])];
		rep(i,0,szt-1) ++tt[cc(t[i])];
		// show();
		bool found=0;
		int j=-1,k=-1;
		rep(i,0,25) {
			if(ss[i] && !tt[i]) {
				found=1;
				j=i;
				--ss[i];
				break;
			}
		}
		if(!found) cout << "B\n";
		else {
			found=0;
			rep(i,0,25) {
				if(tt[i] && !ss[i]) {
					found=1;
					k=i;
					--tt[i];
					break;
				}
			}
			if(!found) cout << "A\n";
			else {
			    if(ss[j]) cout << "A\n";
			    else {
			    	found=0;
			    	rep(i,0,25) {
			    		if(ss[i] && !tt[i]) {
			    			found=1;
			    			--ss[i];
			    			break;
			    		}
			    	}
			    	if(!found) {
			    		if(tt[k]) cout << "B\n";
			    	}
			    	 
			    }
			}
		}
	}
	return 0;
}