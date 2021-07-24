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
int aa[26];
int bb[N][26];
int main() {
	fio;
	fastio;
	string a,b;
	rep(i,0,25) aa[i]=0;
	rep(i,0,N-1) rep(j,0,25) bb[i][j]=0;  
	int sza = a.size();
	int szb = b.size();
	rep(i,0,sza-1) ++aa[(int)(a[i]-97)]
	rrep(i,0,szb-1) {
		rep(j,0,25) b[i][j] = b[i+1][j];
		++b[i][(int)(b[i]-97)];
	}
	return 0;
}