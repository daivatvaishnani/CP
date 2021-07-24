#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("in","r",stdin);
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int A[n];
	long long sum = 0;
	for(int i=0; i<n; ++i) {
		cin >> A[i];
		sum += A[i];
	}
	if(sum & 1) cout << "First\n";
	else {
		int even=0, odd=0;
		for(int i=0; i<n; ++i)  {
			if(A[i] & 1) ++odd;
			else ++even;
		}
		if(odd==0) cout << "Second\n";
		else cout << "First\n";
	} 
}