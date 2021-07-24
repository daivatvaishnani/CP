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
const ll N = 100;
int n,m;
char a[N][N];
bool checkh() {
	int d=n/3;
	if(a[0][0] == a[d][0] || a[d][0] == a[2*d][0] || a[0][0] == a[2*d][0]) return 0;
	char c=a[0][0];
	bool ok=1;
	rep(i,0,n/3-1) {
		rep(j,0,m-1) {
			if(a[i][j]!=c) {
				ok=0;
				break;
			}
		}
	}
	if(ok) {
		c = a[n/3][0];
		rep(i,n/3,2*n/3-1) {
			rep(j,0,m-1) {
				if(a[i][j]!=c) {
					ok=0;
					break;
				}
			}
		}
	}
	if(ok) {
		c = a[2*n/3][0];
		rep(i,2*n/3,n-1) {
			rep(j,0,m-1) {
				if(a[i][j]!=c) {
					ok=0;
					break;
				}
			}
		}
	}
	return ok;
}
bool checkv() {
	int d=m/3;
	if(a[0][0] == a[0][d] || a[0][d] == a[0][2*d] || a[0][0] == a[0][2*d]) return 0;
	char c=a[0][0];
	bool ok=1;
	rep(i,0,n-1) {
		rep(j,0,m/3-1) {
			if(a[i][j]!=c) {
				ok=0;
				break;
			}
		}
	}
	if(ok) {
		c = a[0][m/3];
		rep(i,0,n-1) {
			rep(j,m/3,2*m/3-1) {
				if(a[i][j]!=c) {
					ok=0;
					break;
				}
			}
		}
	}
	if(ok) {
		c = a[0][2*m/3];
		rep(i,0,n-1) {
			rep(j,2*m/3,m-1) {
				if(a[i][j]!=c) {
					ok=0;
					break;
				}
			}
		}
	}
	return ok;
}
int main() {
	// fio;
	fastio;
	cin >> n >> m;
	rep(i,0,n-1) {
		rep(j,0,m-1) cin >> a[i][j];
	}
	if(n%3==0 && m%3!=0) {
		if(checkh()) cout << "YES\n";
		else cout <<"NO\n";	
	}
	else if(n%3!=0 && m%3==0) {
		if(checkv()) cout << "YES\n";
		else cout <<"NO\n";
	}
	else if(n%3!=0 && m%3!=0) cout << "NO\n";
	else {
		if(checkh()) cout << "YES\n";
		else if(checkv()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}