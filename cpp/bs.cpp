#include <bits/stdc++.h>

using namespace std;

const long long M = 1e5;
const long long maxn = 4294967296;
const long long N = 99991;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 0; i < 1e5; ++i) {
		if((maxn - N + i + 1 - M*i > 1) && (maxn - N + i + 1 - M*i <= M)) {
			cout << i << "\n";
			cout << maxn - N + i + 1 - M*i << "\n";
			return 0;
		}
	}	
}