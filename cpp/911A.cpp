#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for(int i=a; i<=b; ++i)
#define RREP(i, a, b) for(int i=b; i<=a; --i)
#define REPC(i, C) for(auto i:C)
#define PI acos(-1)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(C) C.begin(), C.end()
#define RALL(C) C.rbegin(), C.rend()
#define EPS 1e-9
#define INF 1e9

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

vector<int> v, vv;

template<typename T, typename U> inline bool EQ(const T &a, const U &b) {return (abs(a-b) <= EPS);}

int main() {
	// freopen("in", "r", stdin); freopen("out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,val;
	cin >> n;
	int minn = INF;
	REP(i, 0, n-1) {
		cin >> val;
		minn = min(minn, val);
		v.PB(val);
	}
	REP(i,0,n-1) {
		if(v[i]==minn) vv.PB(i);
	}
	sort(ALL(vv));
	int ans = INF;
	REP(i,1,vv.size()-1) {
		ans = min(ans, vv[i]-vv[i-1]); 
	}
	cout << ans << "\n";
  	return 0;
}