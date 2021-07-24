#include <bits/stdc++.h>
using namespace std;

#define msg(s) cout<<s<<"\n"
#define fio freopen("in","r",stdin);freopen("out","w",stdout)
#define fastio ios_base::sync_with_stdio(false)
#define loop(n) int n;cin>>n;while(n--)
#define Loop(n) while(n--)
#define rep(i, a, b)    for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rrep(i, a, b)   for (__typeof (b)i = (b) ; i >= a ; --i)
#define repstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define empty empty()
#define size size()
#define clear clear()
#define pi acos(-1.0)
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef long double lf;
typedef std::vector<int> vi;
typedef std::vector<char> vc;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int N=500;
int a[N],y[N];
int n,k;

int main() {
	//fio;
	fastio;
	cin>>n>>k;
	rep(i,1,n) {cin>>a[i];}
	if(k>=2) {
		rep(i,1,k) {cin>>y[i];}
		cout<<"Yes\n";
		return 0;
	}
	cin>>k;
	rep(i,1,n) {
		if(a[i]==0) {a[i]=k;}
	}
	rep(i,1,n-1) {
		if(a[i+1]<a[i]) {
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}