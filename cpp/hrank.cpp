#include <bits/stdc++.h>
using namespace std;

#define msg(s) cout<<s<<"\n"
#define fio freopen("in","r",stdin);freopen("out","w",stdout)
#define fastio ios_base::sync_with_stdio(false)
#define loop(n) int n;cin>>n;while(n--)
#define Loop(n) while(n--)
#define rep(i, a, b)    for (__typeof (a) i = (a) ; i <= b ; ++i)
#define rep(i, a, b)    for (__typeof (a) i = (a) ; i <= b ; ++i)
#define rrep(i, a, b)   for (__typeof (a)i = (b) ; i >= a ; --i)
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

int main() {
	// loop(t) {
	// 	int n;
	// 	cin>>n;
	// }
	vi v;
	int i=1,val;
	while(1) {
		val=17*i;
		if(val>1e6) {break;}
		if(val&1!=0) {continue;} 
		v.pb(val);
		i++;  
	}
	int count=0;
	repstl(i,v) {
		count++;
		cout<<*i<<"\n";
	}
	cout<<count<<"\n";
}