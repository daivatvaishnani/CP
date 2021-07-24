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

template<typename T, typename U> inline bool EQ(const T &a, const U &b) {return (abs(a-b) <= EPS);}

int main() {
	// freopen("in", "r", stdin); freopen("out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		int s = 0;
		string d;
		cin >> n >> d;
		if(d == "mon") s = 0; 
		if(d == "tues") s = 1;
		if(d == "wed") s = 2;
		if(d == "thurs") s = 3;
		if(d == "fri") s = 4;
		if(d == "sat") s = 5;
		if(d == "sun") s = 6;
		int cnt[7] = {0};
		for(int i=0; i<7; ++i) cnt[i] = n/7;
		int rem = n%7;
		while(rem--) {
			++cnt[s];
			s = (s+1)%7;
		}
		for(int i=0; i<7; ++i) cout << cnt[i] << " ";
		cout << "\n";
	}	
  	return 0;
}