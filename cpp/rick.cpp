#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in","r",stdin);
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	for(int i=0; i<=1000; ++i) {
		for(int j=0; j<=1000; ++j) {
			if(b+i*a == d+j*c) {
				cout << b+i*a << "\n";
				return 0;
			}
		}
	}
	cout << "-1\n";
	return 0;
};