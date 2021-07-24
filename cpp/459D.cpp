#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 6;
int A[2*maxn];
int B[2*maxn];

void pre(int n) {
	int n1 = 0;
	if(log2(n) != (int)log2(n)) {
		n1 = pow(2, (int)log2(n) + 1);
	}
	return n1;
}

int comp(int i, bool m) {
	ans = -1;
	if(m == 1) {
		if()
	}
	else {

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int n, n1;
	n1 = pre(n);
	for(int i = 0; i < n; ++i) {
		cin >> A[n1 + i];
		B[n1 + i] = A[n1 + i];
	}
	for(int i = 0; i < n1 - n; ++i) {
		A[n1 + n + i] = 0;
		B[n1 + n + i] = A[n1 + n + i];
	}
	n = n1;
	for(int i = n - 1; i > 0; --i) {
		A[i] = comp(i);
	}
	return 0;
}