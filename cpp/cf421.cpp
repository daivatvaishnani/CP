#include <bits/stdc++.h>
using namespace std;
int c, v0, v1, a, l;
int main() {
	// freopen("in","r",stdin);
	cin >> c >> v0 >> v1 >> a >> l;
	int read = 0, start = 1, days = 0;
	while(read < c) {
		++days;
		read = start + v0 - 1;
		start = read - l + 1;
		v0 = v0 + a;
		if(v0 > v1)
			v0 = v1;		
	}
	cout << days << "\n";
}