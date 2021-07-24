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
#define rep(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define tc(t) int t;cin>>t;while(t--)  
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
const ll mod = 1e9+7;
const ll N = 1e5+5;
int main() {
	fio;
	fastio;
	ll k;
	string n;
	cin >> k;
	cin >> n;
	ll sn = n.size();
	ll sum=0;
	rep(i,0,sn-1) sum += (int)(n[i]-'0');
	ll bit=0, tsum=sum;
	if(sum >= k) cout << "0\n";
	else {
		string tn = n;
		sort(tn.begin(),tn.end());
		ll stn = tn.size();
		rep(i,0,stn-1) {
			tsum = sum;
			sum += 9-(int)(tn[i]-'0');
			if(tsum!=sum) ++bit;
			if(sum >= k) break;
		} 
		cout << bit << "\n";
	}
	return 0;
}