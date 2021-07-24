#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int n;
	cin >> n;
	long long sum[2];
	sum[0] = 0, sum[1] = 0;
	vector<int> g[2];
	g[0].clear(), g[1].clear();
	int l = 1, r = n, start = 0;
	if(n % 4 == 0) {
		while(l < r) {
			sum[start] += l + r;
			g[start].push_back(l);
			g[start].push_back(r);
			++l, --r;
			start = !start; 
		}
	}
	else if(n % 4 == 1) {
		while(l + 2 != r) {
			sum[start] += l + r;
			g[start].push_back(l);
			g[start].push_back(r);
			++l, --r;
			start = !start;
		}
		sum[start] += r + l + 1;
		sum[!start] += l;
		g[start].push_back(l + 1);
		g[start].push_back(r);
		g[!start].push_back(l);
	}
	else if(n % 4 == 2) {
		while(l + 1 != r) {
			sum[start] += l + r;
			g[start].push_back(l);
			g[start].push_back(r);
			++l, --r;
			start = !start;
		}
		sum[start] += l;
		sum[!start] += r;
		g[start].push_back(l);
		g[!start].push_back(r);
	}
	else if(n % 4 == 3) {
		sum[start] += 3;
		sum[!start] += 3;
		g[start].push_back(1); 
		g[start].push_back(2); 
		g[!start].push_back(3);
		if(n > 3) {
			l = 4;
			r = n;
			while(l < r) {
				sum[start] += l + r;
				g[start].push_back(l);
				g[start].push_back(r);
				++l, --r;
				start = !start;
			}	
		} 
	}
	cout << abs(sum[0] - sum[1]) << "\n";
	cout << g[0].size() << " ";
	for(int i : g[0]) {cout << i << " ";}
	cout << "\n";
	return 0;
}