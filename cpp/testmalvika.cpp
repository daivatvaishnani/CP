#include <iostream>

using namespace std;

ll modulo(ll x){
 	ll N = 1000000007;
    return (x % N + N) %N;
}

ll main() {
	ll A=10, B=17, N=3;	
	ll dp[N]={0};
	dp[0] = A;
	dp[1] = B;
	ll i=2;
	while(i<N) {
		dp[i] = dp[i-1] - dp[i-2];
		i++;
	}
	cout << modulo(dp[N-1]) << endl;
	return 0;
}