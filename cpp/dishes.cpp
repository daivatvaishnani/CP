/***************************************************************************************************/
/*																								   */
/*		BHOPDI WALO, long long ki jageh int ki vajeh se WA aya..bataya karo ll use krna h xD       */
/*																								   */
/***************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define fio freopen("in","r",stdin);freopen("out","w",stdout)
#define fastio ios_base::sync_with_stdio(false)
#define rep(i, a, b)    for (__typeof (b) i = (a) ; i <= b ; ++i)
const int N=1e5+5;
long long a[N],pos[N],neg[N];
long long t,n,sum1,sum2,psum,sum,idx,mul,tsum2;
int main() {
	fio;
	fastio;
	cin>>t;
	while(t--) {
		rep(i,0,N-1) {
			neg[i]=0;
		}
		rep(i,0,N-1) {
			pos[i]=0;
		}
		rep(i,0,N-1) {
			a[i]=0;
		}
		cin>>n;
		rep(i,0,n-1) {
			cin>>a[i];
		}
		sort(a,a+n);
		sum1=0;
		idx=0;
		while(a[idx]<0) {
			neg[idx]=a[idx];
			sum1+=a[idx];
			idx++;
		}
		sum2=0;
		if(idx<n) {
			rep(i,idx,n-1) {
				pos[idx]=a[idx];
				sum2+=a[i];
			}
		}
		mul=n-idx;
		tsum2=sum2*mul;
		psum=sum1+tsum2;
		for(long long i=idx-1; i>=0; i--) {
			sum1-=neg[i];
			sum2+=neg[i];
			mul++;
			tsum2=sum2*mul;
			sum=sum1+tsum2;
			if(sum>psum) {psum=sum;}
		}
		cout<<psum<<"\n";
	}
}