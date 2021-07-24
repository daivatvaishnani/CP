#include <bits/stdc++.h>

using namespace std;

const int maxn = (1 << 17) + 17; 

int A[2*maxn];
bool mode[2*maxn];

void build(int n) {
	for(int i = n - 1; i > 0; --i) {
		if(mode[i] == 0) {
			A[i] = A[2*i] | A[2*i + 1];
			mode[(int) i/2] = 1; 
		}
		else {
			A[i] = A[2*i] ^ A[2*i + 1];
			mode[(int) i/2] = 0;
		}
	}
}

void update(int p,int val, int n) {
	for(A[p += n] = val, p >>= 1; p > 0; p >>= 1) {
		if(mode[p] == 0) {
			A[p] = A[2*p] | A[2*p + 1];	
		}
		else {
			A[p] = A[2*p] ^ A[2*p + 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n, m;
	cin >> n >> m;
	n = 1 << n;
	for(int i = 0; i < n; ++i) {
		cin >> A[i + n];
	}
	build(n);
	while(m--) {
		int p, b;
		cin >> p >> b;
		update(--p, b, n);
		cout << A[1] << "\n";
	}
	return 0;
}