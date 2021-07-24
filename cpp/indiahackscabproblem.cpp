#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define x first
#define y second
#define rep(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define tc(n) int n;cin>>n;while(n--)  
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
#define all(x) x.begin(), x.end()
const ll mod = 1e9+7;
const ll N = 1e5+5;
int a[1341], b[1341];  
int main() {
	fio;
	fastio;
	int s,ss,e,ee;
	for(int i=0; i<1341; ++i) {
		a[i]=0;
		b[i]=0;
	}
	tc(n) {
		cin >> s >> ss >> e >> ee;
		++a[s*60+ss];
		++b[e*60+ee];
	}
	int c=0, f=0;
	rep(i,1,1340) {
		if(a[i]) {
			if(f == 0) c += a[i];
			else {
				if(a[i] > f) c += a[i]-f;
				else f -= a[i]; 
			}
		}
		f += b[i];
	}
	cout << c;
	return 0;
}