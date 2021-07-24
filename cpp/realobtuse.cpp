#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("in","r",stdin);	
	int T;
	cin >> T;
	int K,A,B,D;
	while(T--) {
		cin >> K >> A >> B;
		D = abs(A-B);
		if(D==K-D) cout << "0\n";
		else cout << min(D,K-D)-1 << "\n"; 
	}
}