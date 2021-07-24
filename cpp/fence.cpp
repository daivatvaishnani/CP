#include <bits/stdc++.h>
using namespace std;
#define time cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"	
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
int main() {
	fio;
	fastio;
	vc v1,v2;
	loop(t) {
		int n;
		char val;
		v1.clear;
		v2.clear;
		cin>>n;
		int n1=0,n2=0;
		rep(i,0,n-1) {
			cin>>val;
			if(val=='*') {
				n1++;
			} 
			v1.pb(val);
		}
		int both=0;
		rep(i,0,n-1) {
			cin>>val;
			if(val=='*') {
				n2++;
				if(v1[i]=='*') {
					both++;
				}
			} 
			v2.pb(val);
		}
		int h=1,v=n-1;
		if(both==0) {h--;}
		if(n1==0 && n2==1) {cout<<"0\n"; continue;}
		if(n2==0 && n1==1) {cout<<"0\n"; continue;}
		if(n2==1 && n1==1) {
			cout<<"1\n";
			continue;
		}
		char pv1='r',pv2='r';
		rep(i,0,v1.size-2) {
			if(v1[i]=='.' && v2[i]=='.') {v--; continue;}
			if(h==1 && (v1[i]=='*' && v2[i]=='.') || (v1[i]=='.' && v2[i]=='*')) {
				if(v1[i]=='*') {
					if(pv1=='.') {
						v--;
						pv1='r';
						pv2='r';
						continue;
					}
					pv1='*';
					pv2='.';
					continue;
				}
				if(v1[i]=='.') {
					if(pv1=='*') {
						v--;
						pv1='r';
						pv2='r';
						continue;
					}
					pv1='.';
					pv2='*';
					continue;
				}
			}
			pv1='r';
			pv2='r';
		}
		cout<<(h+v)<<"\n";
	}
}