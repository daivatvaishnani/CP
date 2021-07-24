#include <bits/stdc++.h>									// Range Maximum Query Problem, Tree is 1 indexed, Array is 0-indexed

using namespace std;

const int N = 1e5 + 5;

int A[2 * N];

int pre(int size) {
	int sizen = size;
	if(log2(size) != (int) log2(size)) {
		sizen = pow(2, (int)log2(size) + 1);
	}
	for(int i = 0; i < sizen - size; ++i) {
		A[i + size] = 1;			
	}
	return sizen;
}

void build(int size) {
	for(int i = size - 1; i > 0; --i) {
		A[i] = max(A[2 * i], A[2 * i + 1]);
	}
}

void update(int x, int val, int size) {						// Set val at position x
	A[size + x] = val;
	for(int i = (size + x) / 2 ; i > 0; i >>= 2) {
		A[i] = max(A[2 * i], A[2 * i + 1]);
	}
}

int query(int x, int y, int size) {							// Compute ans for range [x, y]
	int ans = 1;
	for(x += size, y += size; x < y; x >>= 1, y >>= 1) {
		if(x & 1) {
			ans = max(A[x++], ans); 				
		}
		if(!(y & 1)) {
			ans = max(A[y--], ans);
		}
	}
	return ans;
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int n;
	cin >> n;
	n = pre(n);
	for(int i = 0; i < n; ++i) {
		cin >> A[i + n];
	}
	cout << n << "\n";
	cout << n << "\n";
	build(n);
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i) {
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1) {
			update(x, y, n);
		}
		else {
			cout << "The max in range [" << x << ", " << y << "] is " << query(x, y, n) << "\n";
		}
	}
	return 0;
}
