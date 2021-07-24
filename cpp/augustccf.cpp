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
const ll N = 105;
int a[N],no[N];
int noo[8];
bool ok=1,half=0;
void reset() {
	for(int i=0; i<N; ++i) a[i]=0, no[i]=0;
	for(int i=0; i<8; ++i) noo[i]=0;
	ok=1;
	half=0;
}
int main() {
	fio;
	fastio;
	int n,prev=1,val;
	tc(t) {
		reset();
		cin >> n;
		rep(i,1,n) {
			cin >> a[i];
			if(a[i]>7 || a[i]<1) ok=0;
			if(a[i]==7) {
				half=1;
				++noo[a[i]];
			}
			if(a[i]<7 && !half) ++noo[a[i]];
		}
		rep(i,1,7) {
			if(noo[i]==0) {
				ok=0;
				break;
			}
		}
		if(ok) {
			int e=0;
			rep(i,1,6) e+=noo[i];
			if(2*e+noo[7] != n) ok=0;
			else {
				int j=1;
				rep(i,1,7) {
					int tmp=noo[i];
					while(tmp--) {
						no[j]=i;
						++j;
					}
				}
				j=e+noo[7]+1;
				rrep(i,1,6) {
					int tmp=noo[i];
					while(tmp--) {
						no[j]=i;
						++j;
					}
				}
				rep(i,1,n) {
					if(a[i]!=no[i]) {
						ok=0;
						break;
					}
				}
			}
		}
		if(ok) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}