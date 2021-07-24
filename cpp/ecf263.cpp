#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define rep(i,a,b) for(__typeof(b) i=a; i<=b; ++i)
#define tc(t) int t;cin>>t;while(t--)  
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define fio freopen("in","r",stdin);freopen("out","w",stdout);
const ll mod = 1e9+7;
const ll N = 100;
int n,a,b,x,y,cur,ans;
bool ok;
vector<pi> v;
int main() {
	fio;
	fastio;
	cin >> n >> a >> b;
	while(n--) {
		cin >> x >> y;
		if((x <= a  && y <= b) || (x <= b && y <= a)) v.push_back(make_pair(x,y)); 
	}
	if(!v.empty()) {
		ans=0;
		ok=0;
		rep(i,0,v.size()-2) {
			rep(j,i+1,v.size()-1) {
				if((v[j].first <= a-v[i].first && v[j].second <= b-v[i].second) || (v[j].second <= a-v[i].first && v[j].first <= b-v[i].second) || (v[j].first <= a-v[i].second && v[j].second <= b-v[i].first) || (v[j].second <= a-v[i].second && v[j].first <= b-v[i].first)) {
					cur = (v[i].first * v[i].second) + (v[j].first * v[j].second);
					ok=1;
				}
				ans = max(ans,cur); 
			}
		}
		if(ok) cout << ans << "\n";
		else cout << "01\n";
	}
	else cout << "02\n";
	return 0;
}