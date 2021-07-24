#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e9;

int main() {
	freopen("in","r",stdin);
	long long t, n, sum, flag = 1;
	long long check;
	cin >> t;
	while(t--) {
		flag = 1;
		cin >> n;
		if(n >= 4) {
			if(n & 1) {
				sum = n*(n+1)/2;
				check = ((n+1)*sum - n/2 - n*(sum-1)/2 + (sum-1)/2)/sum;
			}
			else {
				check = (n + 3)/2;
			}
			if(flag == 1) {
				for(int i = check; i < check + n ; ++i) {
					cout << i;
					(i == check + n - 1) ? cout << '\n' : cout << ' '; 
				}
			}
		}
		else {
			for(int i=1; i<=n; ++i) {
				cout << i;
				cout << (i == n ? '\n' : ' ');
			}
		}
	}
	return 0;
}