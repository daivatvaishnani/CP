#include <bits/stdc++.h>

using namespace std;

int A[100001];

int main() {
	// freopen("in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T,N;
	cin >> T;
	while(T--) {
		cin >> N;
		if(N & 1) {
			for(int i=2; i<=N-3; i+=2) A[i-1]=i, A[i]=i-1;
			A[N-2]=N-1, A[N-1]=N, A[N]=N-2;
		}
		else {
			for(int i=2; i<=N; i+=2) A[i-1]=i, A[i]=i-1;
		}
		for(int i=1; i<=N; ++i) cout << A[i] << " ";
		cout << "\n";
	}
}