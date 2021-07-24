#include <bits/stdc++.h>

#define msg(x) cout << #x << " : " << x << "\n" 
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int scub = min(2*d, 2*c);
	int sclb = max(c, d);
	int mcub = 2*b;
	int mclb = max(b, max(2*c, 2*d));
	int bcub = 2*a;
	int bclb = max(a, 2*b);
	// msg(scub);
	// msg(sclb);
	// msg(mcub);
	// msg(mclb);
	// msg(bcub);
	// msg(bclb);
	if(bclb >= mcub && mclb >= scub && bcub >= bclb && mcub >= mclb && scub >= sclb) {
		int scs = sclb;
		int mcs = mclb;
		int bcs = bclb;
		if(scub - sclb != 0) {
			scs = scs + rand() % (scub - sclb);
		}
		if(mcub - mclb != 0) {
			mcs = mcs + rand() % (mcub - mclb);
		}
		if(bcub - bclb != 0) {
			bcs = bcs + rand() % (bcub - bclb);
		}
		if(mcs > 2*d) {
			cout << bcs << "\n";
			cout << mcs << "\n";
			cout << scs << "\n";
		}
		else cout << "-1\n";	
	}
	else {
		cout << "-1\n";
	}
	return 0;
}