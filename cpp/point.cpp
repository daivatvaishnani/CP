#include <bits/stdc++.h>
using namespace std;
#define fio freopen("in","r",stdin);freopen("out","w",stdout)
#define fastio ios_base::sync_with_stdio(false)
#define loop(n) int n;cin>>n;while(n--)
#define rep(i, a, b)    for (__typeof (a) i = (a) ; i <= b ; ++i)
#define mp make_pair
#define ff first
#define ss second
typedef pair<int,int> pii;
class cmp {
	public:	
	bool operator()(pii x, pii y) {
		return ((x.ff + x.ss) < (y.ff + y.ss) || ( (x.ff + x.ss) == (y.ff + y.ss) && x.ff < y.ff));
	}
};
int u,v;
set<pii,cmp> s;
int main() {
	fio;
	fastio;
	rep(i,0,1000) {
		rep(j,0,1000) {
			s.insert(mp(i,j));
		}
	}
	loop(t) {
		cin>>u>>v;
		int rank = distance(s.begin(),s.find(mp(u,v)));
		cout<<rank+1<<"\n";	
	}
}