#include <bits/stdc++.h>

using namespace std;

vector<int> cd, precd, tmp, tmp2;
vector<vector<int> > pre;
vector<pair<int, int> > vp;
int a, n, q, t, v1, v2, w, c1, c2;

int min_dist(int v, int c, bool m) {
  int v2;
  // DO SOLVE
  if(!m) {
    v2 = vp[c].first;
    if(v < v2) {
      swap(v, v2);
    }
  }
  else {
    v2 = vp[(c - 1) % n].second;
    if(v < v2) {
      swap(v, v2);
    }
  }
  return min(pre[c][(v - 1) % n] - pre[c][v2], pre[c][n - 1] - pre[c][(v - 1) % n] + pre[c][v2]);
}

int dist(int c1, int c2, bool m) {
  // DO SOLVE
  if(c1 > c2) {
    swap(c1, c2);
  }
  return min(precd[(c2 - 1) % n] - precd[c1] + cd[c1],
              precd[n - 1] - precd[c2] + cd[c2] + min_dist(vp[n - 1].second, 0, 0) + precd[(c1 - 1) % n]);
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &q);
    cd.clear(), precd.clear(), pre.clear(), vp.clear();
    for(int i = 0; i < n; ++i) {
      tmp.clear();
      scanf("%d", &a);
      for(int i = 0; i < a; ++i) {
        scanf("%d", &w);
        tmp.push_back(w);
      }
      if(tmp.size() == 2 && tmp[0] != tmp[1]) {
        tmp[0] = tmp[1] = min(tmp[0], tmp[1]);
        tmp2[0] = tmp2[1] = min(tmp2[0], tmp2[1]);
      }
      if(tmp.size() > 1) {
        for(int i = 1; i < tmp.size(); ++i) {
            tmp[i] += tmp[i - 1];
        }
      }
      pre.push_back(tmp);
    }
    vp.clear();
    for(int i = 0; i < n; ++i) {
      scanf("%d %d %d", &v1, &v2, &w);
      cd.push_back(w);
      precd.push_back(w);
      vp.push_back(make_pair(v1 - 1, v2 - 1));
    }
    // DO PROCESS
    for(int i = 1; i < n; ++i) {
      precd[i] += precd[i - 1] + min_dist(vp[i - 1].second, i, 0);  //v1----o-v2
    }
    for(int i = 0; i < q; ++i) {
      scanf("%d %d %d %d", &v1, &c1, &v2, &c2);
      --v1, --c1, --v2, --c2;
      printf("%d\n", min(min_dist(v1, c1, 0) + dist(c1, c2, 0) + min_dist(v2, c2, 1),
                min_dist(v1, c1, 1) + dist(c1, c2, 1) + min_dist(v2, c2, 0)));
    }
  }
  return 0;
}
