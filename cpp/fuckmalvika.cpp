#include <iostream>

using namespace std;

int modulo(int x){
 	int N = 1000000007;
    return (x % N + N) %N;
}

int main() {
	int cases, A, B, N;	
	cin >> cases;

	while(cases) {
		cin >> A >> B >> N;
		int dp[N]={0};
		dp[0] = A;
		dp[1] = B;
		int i=2;
		while(i<N) {
			dp[i] = dp[i-1] - dp[i-2];
			i++;
		}
		cout << modulo(dp[N-1]) << endl;
		cases--;
	}

	return 0;
}