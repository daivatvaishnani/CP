#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

long long arr[maxn],arr3[3*maxn],maxendh[3*maxn];

int main() {
	// freopen("in","r",stdin);
	int t;
	cin>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		for(int i=0; i<n; ++i) cin>>arr[i];
		for(int i=0; i<3*n; ++i) arr3[i]=arr[i%n];
		// for(int i=0; i<3*n; ++i) cout<<arr3[i]<<" ";
		// cout<<"\n";	
		maxendh[0]=arr3[0];
		for(int i=1; i<3*n; ++i) maxendh[i] = max(arr3[i],maxendh[i-1]+arr3[i]);
		// for(int i=0; i<3*n; ++i) cout<<maxendh[i]<<" ";
		// cout<<"\n";
		long long maxsofar1=arr3[0],maxsofar2=arr3[0],maxsofar3=arr3[0];
		for(int i=1; i<n; ++i) maxsofar1=max(maxsofar1,maxendh[i]);
		for(int i=1; i<2*n; ++i) maxsofar2=max(maxsofar2,maxendh[i]);
		for(int i=1; i<3*n; ++i) maxsofar3=max(maxsofar3,maxendh[i]);
		if(k==1) cout<<maxsofar1<<"\n";
		else cout<<maxsofar2+(k-2)*(maxsofar3-maxsofar2)<<"\n";
		// cout<<"----------------------------------\n";
	}
	return 0;
}