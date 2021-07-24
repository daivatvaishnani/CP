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
	tc(t) {
		int ans=0;
		string s;
		cin >> s;
		int szs = s.size();
		int sum=0;
		rep(i,0,szs-1) sum += s[i]-'0';
		if(sum%9==0) cout << "0\n";
		else {
			int a1 = (sum/9 + 1)*9;
			int a2 = (sum/9)*9;
			cout << min(a1-sum, sum-a2) << "\n";
		}
	}
	return 0;
}