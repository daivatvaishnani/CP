#include <bits/stdc++.h>
using namespace std;
#define fio freopen("in","r",stdin);freopen("out","w",stdout)
#define fastio ios_base::sync_with_stdio(false)
#define rep(i, a, b)    for (__typeof (b) i = (a) ; i <= b ; ++i)
#define repstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != ((s).end()) ; ++i)

const int N=1e5+55;

int a[N];
int t,n,sum1,sum2,psum,sum,idx,mul,tsum2;

int main() {
	fio;
	fastio;
	cin>>n;
	rep(i,1,n) {cin>>a[i];}
	int count=0;
	int sum=0,tsum=0;
	rep(i,1,n) {
		if(a[i]<0) {
			sum+=tsum*count;
			sum+=a[i];
			count=0;
		}
		else {
			tsum+=a[i];
			count++;
		}
	}
	cout<<sum<<"\n";
}