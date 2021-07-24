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
int main() {
	// fio;
	fastio;
	string o1;
	cin >> o1;
	vector<int> to,th;
	rep(i,0,2) to.pb((int)(o1[i]-'0'));
	rep(i,3,5) th.pb((int)(o1[i]-'0'));
	int sto=0, sth=0;
	rep(i,0,2) {
		sto += to[i];
		sth += th[i];
	}
	if(sto != sth) {
		sort(to.begin(),to.end());
		sort(th.begin(),th.end());
		if(sto > sth) {
			int m1=0, m2=0;
			int tsto=sto, tsth=sth;
			rep(i,0,2) {
				if(tsth >= tsto) break;
				tsth += 9-th[i];
				++m1;
			}
			tsto=sto, tsth=sth;
			rrep(i,0,2) {
				if(tsto <= tsth) break;
				tsto -= to[i];
				++m2;
			}
			cout << min(m1,m2) << "\n";
		}
		else {
			int m1=0, m2=0;
			int tsto=sto, tsth=sth;
			rep(i,0,2) {
				if(tsto >= tsth) break;
				tsto += 9-to[i];
				++m1;
			}
			tsto=sto, tsth=sth;
			rrep(i,0,2) {
				if(tsth <= tsto) break;
				tsth -= th[i];
				++m2;
			}
			cout << min(m1,m2) << "\n";
		}
	}
	else cout << "0\n";
	return 0;
}