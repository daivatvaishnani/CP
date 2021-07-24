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
const ll N = 5005;
char a[N][N];
int pre[N][N];
int main() {
	// fio;
	fastio;
	int n,m;
	cin >> n >> m;
	rep(i,0,N-1) rep(j,0,N-1) a[i][j]='0';
	rep(i,1,n) rep(j,1,m) cin >> a[i][j];
	rep(i,0,N-1) rep(j,0,N-1) pre[i][j] = (a[i][j]=='1') ? 1 : 0;
	rep(i,1,N-1) pre[i][0] += pre[i-1][0];
	rep(i,1,N-1) pre[0][i] += pre[0][i-1];
	rep(i,1,N-1) rep(j,1,N-1) pre[i][j] += pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
	int minans=1e9;
	int ans=0;
	for(int k=2; k<=2500; ++k) {
		ans = 0;
		int nn=n,mm=m;
		if(nn%k!=0) nn = (nn/k+1)*k;
		if(mm%k!=0) mm = (mm/k+1)*k;    
		for(int i=1; i<=nn-k+1; i+=k) {
			for(int j=1; j<=mm-k+1; j+=k) {
				int no = pre[i+k-1][j+k-1]-pre[i+k-1][j-1]-pre[i-1][j+k-1]+pre[i-1][j-1]; 
				ans += min(k*k-no,no);
			}
		}
		minans = min(ans, minans); 
	}
	cout << minans << "\n";
	return 0;
}