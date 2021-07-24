#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
vector<ll> Solve(vector<ll> &A) {
    vector<ll> ans;
    ll ansstart=0, ansend=-1;
    ll start=0, end=-1, maxsum=-1, sum=0, tsum=0;
    for(int i=0; i<A.size(); ++i) {
    	if(A[i] >= 0) {
    		sum += A[i];
    		end = i;
    	}
    	else {
    		if(maxsum < sum) {
    			ansstart = start;
    			ansend = end;
    			maxsum = sum;
    		}
    		start = i+1;
    		sum = 0;
    	}
    }
   	if(maxsum < sum) {
		ansstart = start;
		ansend = end; 		
    }
    for(ll i=ansstart; i<=ansend; ++i) ans.push_back(A[i]);
    return ans;
}

int main() {
	fio;
	fastio;
	vector<ll > A;
	ll size,val;
	cin >> size;
	rep(i,0,size-1) {
		cin >> val;
		A.pb(val);
	}
	rep(i,0,A.size()-1) cout << A[i] << "\n";
	cout << "\n";
	vector<ll > B = Solve(A);
	rep(i,0,B.size()-1) cout << B[i] << " ";
	return 0;
}