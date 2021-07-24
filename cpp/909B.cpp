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

int ans(int n) {
	if(n == 2) return 2;
	else if(n == 3) return 4; 
	return n + ans(n-2);
}

int main() {
	// freopen("in", "r", stdin); freopen("out", "w", stdout);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	cout << ans(n) << "\n";
  	return 0;	
}

/*




-			-----		-
 -			-----		 -
  -		3	-----		  -	
   -		
    -
--			-----       --
 --		1	-----        --
  --		
   --		 ---        ---
---			 ---
 ---         ---
  ---
----
 ----
-----

*/