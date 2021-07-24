#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	long double n, rootn, del;
	cin >> n;
	rootn = sqrt(n);
	long long rootni = (int) rootn;
	long long ni, per, diff, deli, nni, left;
	if(rootni == rootn) {
		per = 4 * rootn;
	}
	else {
		++rootni;
		ni = pow(rootni, 2);
		diff = ni - n;
		del = diff / (rootni + 0.0);
		deli = (int) del;
		if(deli == del) {
			per = 2 * rootni + 2 * (rootni - deli);
		}
		else {
			per = 2 * rootni  + 2 * (rootni - deli - 1) + 2;
		}
	}
	cout << per << "\n";
	return 0;
}