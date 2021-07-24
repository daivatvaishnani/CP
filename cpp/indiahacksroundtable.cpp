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
#define rep(i,a,b) for(auto i=a; i<=b; ++i)
#define repstl(i,v) for(auto i:v)
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
const ll mod = 1e9+7;
const ll N = 1e5+5;
int main() {
	fio;fastio;
	int n, k, x, killed=0;
	cin >> n >> k >> x;
	int rem = n;
	bool alive[n];
	for(int i=0; i<n; ++i) alive[i]=1;
	int z;
	while(1) {
		if(x==0) z=n%k;
		else z=x%k;
		if(x==n) x=0;
		if(z==0) x=(x+1)%n; 
		else if(rem-1 > z) {
			for(int i=0; i<z;) {
				if(alive[(x+1)%n]) {
					alive[(x+1)%n]=0;
					++i;
					--rem;					
				}
				x=(x+1)%n;
			}
			while(!alive[x]) x=(x+1)%n;
		}
		else break;
	}
	if(x==0) x=n;
	cout << x << "\n";
	return 0;
}