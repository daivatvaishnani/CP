#include <bits/stdc++.h>

using namespace std;

#define snap(x) cout << #x << " : " << x << "\n"

vector<int> x, y;

int m, q, val, xi, yi;

double get(int t0, int t1, bool p) {
	int ans = 0;
	if(!p) {
		for(int i = 0; i < x.size(); ++i) {
			ans += t0 + t1 * x[i] - y[i];
		}
	}
	else {
		for(int i = 0; i < y.size(); ++i) {
			ans += (t0 + t1 * x[i] - y[i]) * x[i];
		}	
	}
	return ans;
}

double j(int t0, int t1) {
	int ans = 0;
	for(int i = 0; i < x.size(); ++i) {
		ans += pow((t0 + t1 * x[i] - y[i]), 2);
	}
	return ans / m;
}

pair<double, double> getLineParameters() {
	double t0 = 0, t1 = 0, alpha = 0.05, t01 = 0, t11 = 0;
	while(get(t0, t1, 0) != 0 && get(t0, t1, 1) != 0) {
		t01 = t0 - alpha * get(t0, t1, 0) / m;
		t11 = t1 - alpha * get(t0, t1, 1) / m;
		t0 = t01;
		t1 = t11;
	}
	return {t0, t1};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	cin >> m >> q;
	for(int i = 0; i < m; ++i) {
		cin >> xi >> yi;
		x.push_back(xi);
		y.push_back(yi);
	}
	pair<double, double> LineParameters = getLineParameters();
	cout << LineParameters.first << " " << LineParameters.second << "\n";
	while(q--) {
		cin >> val;
		cout << val << "\n";
	}
	return 0;
}