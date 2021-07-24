/**
* Problem Link: https://www.codechef.com/APRIL20B/problems/FCTRE
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const int maxk = 25;

vector<int> graph[maxn];
int sum[maxn], a[maxn], d[maxn];
int table[maxk][maxn];

vector<pair<int, int> > tour;

void dfs(int node, int par, int n, int depth) {
    if(node >= 1 && node <= n) {
        if(d[node] == -1) {
            d[node] = depth;
        }
        if(sum[node] == -1) {
            int path_sum = 0;
            if(par >= 1 && par <= n) {
                path_sum += sum[par];
            }
            path_sum += a[node];
            sum[node] = path_sum;
            for(int child : graph[node]) {
                dfs(child, node, n, d[node] + 1);
            }
        }
        cout << node << " " << d[node] << "\n";
        tour.push_back({node, d[node]});
    }
}

void preprocess(int n) {
    // for(int i = 1; i <= n; ++i) {
    //     table[0][i] = tour[i].fi;
    // }
    // for(int k = 1; k <= log2(n-k); ++k) {
    //     for(int i = 1; i <= n; ++i) {
    //         table[k][i] = min(table[k-1][i], table[k-1][i + (1 << (k-1))]);
    //     }
    // }
}

int solve(int u, int v, int n) {
    return 0;
}

void reset() {
    memset(sum, -1, sizeof(sum));
    memset(a, -1, sizeof(a));
    memset(d, -1, sizeof(d));
    memset(table, INT_MAX, sizeof(table));
    memset(graph, {}, sizeof(graph));
    tour.clear();
    tour.push_back({-1, -1});
}

void test_case() {
    int n;
    cin >> n;
    for(int i = 1; i <= n-1; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(1, -1, n, 1);
    cout << "\n";
    for(int i = 1; i <= 2 * n - 1; ++i) {
        cout << tour[i].first << " " << tour[i].second << "\n";
    }
    preprocess(2 * n - 1);
    cout << "\n";
    for(int i = 1; i <= n; ++i) {
        cout << i  << ": " << sum[i] << "\n";
    }
    int q;
    cin >> q;
    for(int i = 1; i <= q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << solve(u, v, n) << "\n";
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        reset();
        test_case();
    }
    return 0;
}