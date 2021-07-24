#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 55;
int N, Q, L, R;
int q, x, y;
int A[maxn];

void do1() {
	A[x] = y;
}

void do2() {
	long long s1=0,s2=0,sum1=0,sum2=0;
	for(long long i = x; i <= y; ++i) {
		if(A[i] > L) {
			sum1 += s1 * (s1 + 1) / 2;
			s1 = -1;
		}
		++s1;
	}
	sum1 += s1 * (s1 + 1) / 2;
	for(long long i = x; i <= y; ++i) {
		if(A[i] > R) {
			sum2 += s2 * (s2 + 1) / 2;
			s2 = -1;
		}
		++s2;
	}
	sum2 += s2 * (s2 + 1) / 2;
	cout << abs(sum2 - sum1) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> N >> Q >> L >> R;
	for(int i = 0; i < Q; ++i) {
		cin >> q >> x >> y;
		if(q == 1) {
			do1();
		}
		else {
			do2();
		}
	}	
	return 0;
}