#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;  
int sieve[N], a[N];
int t, l, r, pdivs, divi, divs;
int perfect(int x) {	
	divi = x;
	divs = sieve[x];
	pdivs = 0;
	while(1) {
		pdivs = divs;
		divi = divi/divs;
		divs = sieve[divi];
		if(pdivs == divs)
			return 0;
		if(divi == divs)
			return 1;
	}
}
int main() {
	freopen("in","r",stdin);
    ios_base::sync_with_stdio(false);
    sieve[1] = 1;
    for(int i=0; i<N; ++i)
    	sieve[i] = -1;
    for(int i=2; i*i<N; ++i) {
        if(sieve[i]==-1) {
            sieve[i] = i;
            for(int j=2; i*j<N; ++j) {
                sieve[i*j] = i;  
            }
        }
    }
    a[0] = 0;
    a[1] = 1; 
    for(int i=2; i<N; ++i) a[i] = 1; 
    for(int i=2; i*i<N; ++i) {
    	if(a[i]==1 && !perfect(i)) {
    		for(int j=1; i*j<N; ++j)
    		    a[i*j] = 0;
    	}
    }
    for(int i=2; i<N; ++i) {
    	a[i] = a[i-1] + a[i];
    }
    cin >> t;
    while(t--) {
    	cin >> l >> r;
    	cout << a[r] - a[l-1] << "\n";
    }
    return 0;
}
