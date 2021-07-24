#include <bits/stdc++.h>

using namespace std;

vector<int> tmp, cd, precd;
vector<pair<int, int> > vp;
vector<vector<int> > pre;
int t, n, q, a, w, n1, n2, c1, c2;

int min_dist(int v1, int c1, bool m) {
	int v, ans, nodes = pre[c1].size();
	if(pre[c1].size() > 2) {
		if(!m) {
			v = vp[c1].first;
		}
		else {
			v = vp[(c1 - 1) % n].second;
		}
		if(v == v1) {
			return 0;
		}
		if(v < v1) {
			swap(v, v1);
		}
		if(v1 == 0) {
			ans = pre[c1][v - 1];
		}
		else {
			ans = pre[c1][v - 1] - pre[c1][v1 - 1];
		}
		return min(ans, pre[c1][nodes - 1] - ans);
	}
	else {
		if(!m) {
			v = vp[c1].first;
		}
		else {
			v = vp[(c1 - 1) % n].second;
		}
		if(v == v1) {
			return 0;
		}
		else {
			return pre[c1][v];
		}
	}
}

int dist(int c1, int c2, bool m) {
	int ans;
	if(c2 < c1) {
		swap(c1, c2);
	}
	ans = precd[c2 - 1] - precd[c1] + cd[c1];
	if(!m) {
		return ans;
	}
	else {
		return (precd[n - 1] - ans - min_dist(vp[c1].first, c1, 1) - min_dist(vp[c2].first, c2, 1) + min_dist(vp[0].first, 0, 1));
	}
}

int ans(int v1, int c1, int v2, int c2) {
	if(c2 < c1) {
		swap(c1, c2);
	}
	int ans1 = min_dist(v1, c1, 0) + dist(c1, c2, 0) + min_dist(v2, c2, 1);
	int ans2 = min_dist(v1, c1, 1) + dist(c1, c2, 1) + min_dist(v2, c2, 0);
	return min(ans1, ans2);
}

int main() {
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		pre.clear(), vp.clear(), cd.clear(), precd.clear();
		scanf("%d %d", &n, &q);
		for(int i = 0; i < n; ++i) {
			tmp.clear();
			scanf("%d", &a);
			for(int i = 0; i < a; ++i) {
				scanf("%d", &w);
				tmp.push_back(w);
			}
			if(tmp.size() > 1) {
				if(tmp.size() == 2) {
					tmp[0] = tmp[1] = min(tmp[0], tmp[1]);
				}
				else {
					for(int i = 1; i < tmp.size(); ++i) {
						tmp[i] += tmp[i - 1];
					}
				}
			}
			pre.push_back(tmp);
		}
		for(int i = 0; i < n; ++i) {
			scanf("%d %d %d", &n1, &n2, &w);
			vp.push_back(make_pair(--n1, --n2));
			cd.push_back(w);
			precd.push_back(w);
		}
		if(precd.size() > 1) {
			for(int i = 1; i < n; ++i) {
				precd[i] += precd[i - 1] + min_dist(vp[i - 1].second, i, 0);
			}
		}
		for(int i = 0; i < q; ++i) {
			scanf("%d %d %d %d", &n1, &c1, &n2, &c2);
			printf("%d\n", ans(--n1, --c1, --n2, --c2));
		}
	}
	return 0;
}
