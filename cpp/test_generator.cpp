#include <bits/stdc++.h>

using namespace std;

int T,rn,rm,n,m,ti,li,ri;

int main() {
	T=1;
	n = 100000;
	m = 10000;
	freopen("test_cases","w",stdout);
	while(T--) {
		// n = 1 + rand()%rn;
		// m = 1 + rand()%rm;
		// cout << n << " " << m;
		cout << n << ' ' << m << '\n';
		for(int i=1; i<=m; ++i) {
			if(i==1) ti=1;
			else ti = 2/*rand()%2 + 1*/;
			if(ti==1) {
				li = 1/* + rand()%n*/;
				ri = n/*li + rand()%(n-li+1)*/;
				// if(ri > n) ri -= n-li;
			}
			else {
				li = 1/* + rand()%(i-1)*/;
				ri = i-1/*li + rand()%(i-li+1)-1*/; 
			}
			cout << ti << ' ' << li << ' ' << ri << '\n'; 
		}
	}
}