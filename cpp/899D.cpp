#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	string n;
	cin >> n;
	int m9 = n.size() - 1;
	if(n[0] >= '5')	++m9;
	cout << m9 << "\n";
	// maximum 9 possible is m9
	long long ans = 0;
	if(m9 == n.size()) {
		ans += 
	}
	return 0;
}