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
#define end 'E'
#define start 'S'
#define khali '.'
#define obstacle '#'

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

char maz[50][50];
int n, m;

template<typename T, typename U> inline bool EQ(const T &a, const U &b) {return (abs(a-b) <= EPS);}

int follow(string c, string s, int i, int j) {
	char u = c[0], d = c[1], l = c[2], r = c[3];
	string res = "";
	bool ok = 1;
	res += maz[i][j];
	REPC(ch,s) {
		if(ch == u) {
			if(i == 0) {
				ok = 0;
				break;
			}
			res += maz[--i][j];
		}
		if(ch == d) {
			if(i == n-1) {
				ok = 0;
				break;
			}
			res += maz[++i][j];
		}
		if(ch == l) {
			if(j == 0) {
				ok = 0;
				break;
			}
			res += maz[i][--j];
		}
		if(ch == r) {
			if(j == m-1) {
				ok = 0;
				break;
			}
			res += maz[i][++j];
		}
	}
	bool reached = 0;
	REPC(ch, res) {
		if(ch == end) {
			reached = 1;
			break;
		}
		if(ch == obstacle) {
			break;
		}
	}
	if(reached) return 1;
	else return 0;
}

int main() {
	// freopen("in", "r", stdin); freopen("out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int si = -1, sj = -1, ei = -1, ej = -1; 
	REP(i,0,n-1) {
		REP(j,0,m-1) {
			cin >> maz[i][j];
			if(maz[i][j] == start) {
				si = i;
				sj = j;
			}
			if(maz[i][j] == end) {
				ei = i;
				ej = j;
			}
		}
	}
	string s;
	cin >> s;
	vector<string> perms = {"0123", "0132",	"0231",	"0213",	"0312",	"0321",
							"1023",	"1032",	"1203",	"1230",	"1302",	"1320",
							"2013",	"2031",	"2103",	"2130",	"2301",	"2310",
							"3012",	"3021",	"3102",	"3120",	"3201",	"3210" };
	int cnt = 0;
	REPC(c, perms) {
		cnt += follow(c, s, si, sj);
	}
	cout << cnt << "\n";
  	return 0;
}
