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

int no[100];

template<typename T, typename U> inline bool EQ(const T &a, const U &b) {return (abs(a-b) <= EPS);}

int main() {
	// freopen("in", "r", stdin); freopen("out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	int no[n] = {0};
	int ans1 = INF;
	int p = 0;
	int ta = a, tb = b;
	while(ta--) {
		++no[p];
		if(p == n/2 - 1) p = 0;
		else ++p;
	}
	p = n/2;
	while(tb--) {
		++no[p];
		if(p == n - 1) p = n/2;
		else ++p;
	}
	REP(i,0,n-1) ans1 = min(ans1, no[i]);
	REP(i,0,n-1) no[i] = 0;
	int ans2 = INF;
	p = 0;
	while(b--) {
		++no[p];
		if(p == n/2 - 1) p = 0;
		else ++p;
	}
	p = n/2;
	while(a--) {
		++no[p];
		if(p == n - 1) p = n/2;
		else ++p;	
	}
	REP(i,0,n-1) ans2 = min(ans2, no[i]);
	if(ans1 == 0) ans1 = INF;
	if(ans2 == 0) ans2 = INF;
	cout << min(ans1, ans2);
  	return 0;
}