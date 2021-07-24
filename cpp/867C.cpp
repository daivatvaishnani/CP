#include <bits/stdc++.h>

using namespace std;
typedef pair<long long, long long> type;

const int N = 1e5+5;
long long n, s, a, b, c, np, ts, n1, n2;
vector<type> va, vb;
vector<long long> vn;
vector<bool> t;

#define ni first
#define hi second

bool cmp(type p, type q) {
	if(p.hi == q.hi) return p.ni < q.ni;
	return p.hi > q.hi;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		ts += a;
		vn.push_back(a);
		va.push_back(make_pair(i, a * b));
		vb.push_back(make_pair(i, a * c));
		t.push_back(0);
	}
	np = (ts % s == 0) ? ts / s : ts / s + 1;
	cout << np << "\n";
	sort(va.begin(), va.end(), cmp);
	sort(vb.begin(), vb.end(), cmp);
	for(int i = 0; i < n; ++i) {
		cout << va[i].ni << " " << va[i].hi << " " << vb[i].ni << " " << vb[i].hi << "\n";
	}
	for(int i = 0; i < n; ++i) {
		if(va[i].ni == vb[i].ni) {
			if(va[i].hi >= vb[i].hi) {
				n1 += vn[va[i].ni];
			}
			else {
				n2 += vn[va[i].ni];
			}
			t[va[i].ni] = 1;
		}
		else {
			if(t[va[i].ni] == 0) {
				n1 += vn[va[i].ni];
				t[va[i].ni] = 1;
			}
			if(t[vb[i].ni] == 0) {
				n2 += vn[vb[i].ni];
				t[vb[i].ni] = 1;	
			}
		}
	}
	cout << n1 << " " << n2 << "\n";
	return 0;
}