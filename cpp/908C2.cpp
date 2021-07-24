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

ld x[1000];
ld y[1000];

vector<int> pts;

template<typename T, typename U> inline bool EQ(const T &a, const U &b) {return (abs(a-b) <= EPS);}

int main() {
	// freopen("in", "r", stdin); freopen("out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << setprecision(12);
	ld n,r;
	cin >> n >> r;
	REP(i,0,n-1) cin >> x[i];
	y[0] = r;
	cout << y[0] << " ";
	REP(i,1,n-1) {
		ld maxy = r;
		REP(j,0,i-1) {
			if(abs(x[j]-x[i]) <= 2*r) {
				ld d = sqrt(4*r*r - (x[j]-x[i])*(x[j]-x[i])) + y[j];
				maxy = max(maxy, d);
			}
		}
		y[i] = maxy;
		cout << y[i] << " "; 
	}
  	return 0;
}