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
#define tc(t) int t;cin>>t;while(t--)  
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
const ll mod = 1e9+7;
const ll N = 1e3;
ll ms[N],os[N],mjo[N],tjo[N];
string quali[N];
ll n,m,a,b,c;
void reset() {
	rep(i,0,N-1) ms[i]=0, os[i]=0, mjo[i]=0, tjo[i]=0; 
}
bool qual(int i, int j) {
	return quali[i][j]=='1' ? true : false;
}
ll gs(int i, int j) {
	if(qual(i,j)) {
		if(ms[i] <= os[j] && mjo[j] > 0) return os[j];
		else return 0;
	}
	else return 0;
}
int main() {
	fio;
	fastio;
	tc(t) {
		reset();
		cin >> n >> m;
		rep(i,0,n-1) cin >> ms[i];
		rep(i,0,m-1) cin >> os[i] >> mjo[i];
		rep(i,0,n-1) cin >> quali[i];
		rep(i,0,m-1) tjo[i]=mjo[i];
		a=0,b=0,c=0;
		rep(i,0,n-1) {
			ll maxs=0, comp=-1;
			rep(j,0,m-1) {
				if(maxs < gs(i,j)) {
					maxs = gs(i,j);
					comp=j;
				}   
			}
			if(comp >= 0) {
				++a, b += maxs, --mjo[comp];
			}
		}
		rep(i,0,m-1) {
			if(mjo[i]==tjo[i]) ++c;
		}
		cout << a << " " << b << " " << c << "\n"; 
	}
	return 0;
}