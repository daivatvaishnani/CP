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
	fio;
	fastio;
	int T,SZS;
	cin >> T;
	bool OK;
	string S;
	while(T--) {
		cin >> S;
		SZS = S.size();
		OK=0;
		for(int i=0; i<SZS-2; ++i) {
			if(S[i]==S[i+1] || S[i]==S[i+2]) {
				OK=1;
				break;
			}
		}
		if(OK) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}