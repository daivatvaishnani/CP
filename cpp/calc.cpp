#include <bits/stdc++.h>
using namespace std;
#define fio freopen("in","r",stdin);freopen("out","w",stdout)
#define fastio ios_base::sync_with_stdio(false)
#define rep(i, a, b)    for (__typeof (b) i = (a) ; i <= b ; ++i)
#define repstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != ((s).end()-1) ; ++i)

const  long long N=1e5+55;
const  long mod = 1000000007;
 long long x[N],y[N],z[N],sx[N],sz[N];
 long long mul1,mul2,sum;
 long long p,q,r,t,ix,iz;

int bsx2(int l, int r, int key)
{
	int m;

	while( r - l > 1 )
	{
		m = l + (r - l)/2;

		if( x[m] <= key )
			l = m;
		else
			r = m;
	}

	return l;
}

int bsx(int size, int key)
{
	if( key < x[1] )
		return -1;

	return bsx2(1, size, key);
}

int bsz2(int l, int r, int key)
{
	int m;

	while( r - l > 1)
	{
		m = l + (r - l)/2;

		if( z[m] <= key )
			l = m;
		else
			r = m;
	}

	return l;
}

int bsz(int size, int key)
{
	if( key < z[1] )
		return -1;

	return bsz2(1, size, key);
}

//  long long  bsx( long long  l,  long long  r,  long long  val) {
// 	 long long  m;
// 	while(r-l>1) {
// 		m = l + (r-l)/2;
// 		if(x[m]==val) 
// 			return m;
// 		else if(x[m]<val)
// 			l=m+1;
// 		else 
// 			r=m-1;
// 	}
// 	return l;
// }

//  long long  bsz( long long  l,  long long  r,  long long  val) {
// 	 long long  m;
// 	 if(val<z[0]) {return -1;}
// 	while(r-l>1) {
// 		m = l + (r-l)/2;
// 		if(z[m]==val) 
// 			return m;
// 		else if(z[m]<val)
// 			l=m+1;
// 		else 
// 			r=m-1;
// 	}
// 	return l;
// }

int main () {
	fio;
	fastio;
	cin>>t;
	while(t--) {
		cin>>p>>q>>r;
		rep(i,1,p) {cin>>x[i];}
		rep(i,1,q) {cin>>y[i];}
		rep(i,1,r) {cin>>z[i];}
		sort(x+1,x+p+1);
		sort(y+1,y+q+1);
		sort(z+1,z+r+1);
		rep(i,1,p) {
			sx[i]=sx[i-1]+x[i];
		}
		rep(i,1,r) {
			sz[i]=sz[i-1]+z[i];
		}
		sum=0;
		rep(i,1,q) {
			ix = bsx(p+1,y[i]);
			iz = bsz(r+1,y[i]);
			if(ix<=0 || iz<=0) {continue;}
			mul1 = (ix*y[i] + sx[ix]);
			mul2 = (iz*y[i] + sz[iz]);
			sum = sum + ((mul1%mod)*(mul2%mod))%mod	;
		}
		sum=sum%mod;
		cout<<sum<<"\n"; 
	 }
}