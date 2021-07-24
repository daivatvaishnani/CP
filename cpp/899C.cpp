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
	int l = 1, r = n;
	int start = 0;
	int cnt = 0;
	while(l <= r) {
		if(l == r) {
			if(sum[0] + l - sum[1] < sum[1] + l - sum[0]) {
				g[0].push_back(l);
				sum[0] += l;
				break;
			}
			else {
				g[1].push_back(l);
				sum[1] += l;
				break;
			}
		}
		else if(l + 2 == r && cnt % 2 == 0) {
			cout << "bitchyo\n";
			g[start].push_back(l);
			g[start].push_back(l + 1);
			g[!start].push_back(r);
			sum[start] += 2*l + 1;
			sum[!start] += r;
			break;
		}
		else if(l + 2 == r && cnt % 2 != 0) {
			g[start].push_back(r);
			g[start].push_back(r - 1);
			g[!start].push_back(l);
			sum[start] += 2*r - 1;
			sum[!start] += l;
			break;
		}
		else if(l + 1 == r && cnt % 2 == 0) {
			g[start].push_back(l);
			g[!start].push_back(r);
			sum[start] += r;
			sum[!start] += l;
			break;
		}
		else {
			g[start].push_back(l);
			g[start].push_back(r);
			sum[start] += (l + r);
		}
		++l, --r;
		start = !start;
		++cnt;
	}
	cout << abs(sum[0] - sum[1]) << "\n";
	cout << g[0].size() << " ";
	for(int i : g[0]) {
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}