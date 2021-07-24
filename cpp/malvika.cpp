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
		int dp[N+1]={0};
		dp[1] = A;
		dp[2] = B;
		int i=3;
		while(i<=N) {
			dp[i] = dp[i-1] - dp[i-2];
			i++;
		}
		cout << modulo(dp[N]) << endl;
		cases--;
	}

	return 0;
}
