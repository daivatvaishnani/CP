/**
* Problem Link: https://www.codechef.com/APRIL20B/problems/FCTRE
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 5;
const ll maxk = 25;
const ll mod = 1e9 + 7;

class SparseTable {
    ll maxk, n;
    vector<vector<ll> > table;
    vector<vector<ll> > id;
    vector<ll> a;
    
    void construct() {
        for(ll i = 0; i < n; ++i) {
            table[0][i] = a[i];
            id[0][i] = i;
        }
        for(ll k = 1; k <= maxk; ++k) {
            for(ll i = 0; i < n; ++i) {
                if(i + (1 << k) - 1 < n) {
                    table[k][i] = min(table[k-1][i], table[k-1][i + (1 << (k-1))]);
                    id[k][i] = (table[k][i] == table[k-1][i]) ? id[k-1][i] : id[k-1][i + (1 << (k-1))];
                }
            }
        }
    }
public:
    SparseTable() {

    }

    SparseTable(vector<ll> &arr) {
        a = arr;
        n = a.size();
        maxk = log2(n);
        table.resize(maxk + 1);
        id.resize(maxk + 1);
        for(ll k = 0; k <= maxk; ++k) {
            table[k].resize(n, LLONG_MAX);
            id[k].resize(n, -1);
        }
        construct();
    }

    ll getMin(ll l, ll r) {
        ll len = (r - l + 1);
        ll k = log2(len);
        ll m = r - (1 << k) + 1;
        ll rmin = min(table[k][l], table[k][m]);
        return min(table[k][l], table[k][m]);
    }

    ll getMinId(ll l, ll r) {
        ll len = (r - l + 1);
        ll k = log2(len);
        ll m = r - (1 << k) + 1;
        ll rmin = min(table[k][l], table[k][m]);
        ll minId = (rmin == table[k][l]) ? id[k][l] : id[k][m];
        return minId;
    }

    void print() {
        for(ll i = 0; i < n; ++i) {
            cout << i << ": ";
            for(ll k = 0; k <= maxk; ++k) {
                cout << table[k][i] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        for(ll i = 0; i < n; ++i) {
            cout << i << ": ";
            for(ll k = 0; k <= maxk; ++k) {
                cout << id[k][i] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

vector<ll> graph[maxn];
ll a[maxn], d[maxn], id[maxn];

unordered_map<ll, ll> sum[maxn];

vector<pair<ll, ll> > tour;

SparseTable RMQ;

ll mul(ll a, ll b) {
    return (a % mod * b % mod) % mod;
}

void reset() {
    memset(a, -1, sizeof(a));
    memset(d, -1, sizeof(d));
    memset(id, -1, sizeof(id));
    for(ll i = 0; i < maxn; ++i) {
        sum[i].clear();
        graph[i].clear();
    }
    tour.clear();
    tour.push_back({LLONG_MAX, LLONG_MAX});
}

void print_tour(ll n) {
    cout << "id: ";
    for(ll i = 1; i <= 2 * n - 1; ++i) {
        cout << tour[i].first << " ";
    }
    cout << "\n";
    cout << "dp: ";
    for(ll i = 1; i <= 2 * n - 1; ++i) {
        cout << tour[i].second << " ";
    }
    cout << "\n";
}

void print_sum(ll n) {
    for(ll i = 1; i <= n; ++i) {
        cout << i << ": " << a[i] << "\n";
        for(auto p : sum[i]) {
            cout << p.first << " " << p.second << "\n";
        }
        cout << "\n";
    }
}

unordered_map<ll, ll> factors(ll n) {
    unordered_map<ll, ll> f;
    for(ll x = 2; x * x <= n; x++) {
       while(n % x == 0) {
            f[x]++;
            n /= x;
        }
    }
    if(n > 1) {
        f[n]++;
    }
    return f;
}

unordered_map<ll, ll> add_sum(unordered_map<ll, ll> &sum1, unordered_map<ll, ll> sum2) {
    unordered_map<ll, ll> nodesum = sum1;
    for(auto p : sum2) {
        nodesum[p.first] += p.second;
    }
    return nodesum;
}

unordered_map<ll, ll> sub_sum(unordered_map<ll, ll> &sum1, unordered_map<ll, ll> sum2) {
    unordered_map<ll, ll> nodesum = sum1;
    for(auto p : sum2) {
        nodesum[p.first] -= p.second;
    }
    return nodesum;
}

void dfs(ll node, ll par, ll n, ll depth) {
    if(node >= 1 && node <= n) {
        if(d[node] == -1) {
            d[node] = depth;
            sum[node] = factors(a[node]);
            if(par >= 1 && par <= n) {
                sum[node] = add_sum(sum[node], sum[par]);
            }
            for(ll child : graph[node]) {
                dfs(child, node, n, d[node] + 1);
            }
        }
        if(id[node] == -1) {
            id[node] = tour.size();
        }
        tour.push_back({node, d[node]});
    }
}

ll find_lca(ll u, ll v, ll n) {
    ll x = id[u], y = id[v];
    if(x > y) {
        swap(x, y);
    }
    ll low = RMQ.getMinId(x, y);
    return tour[low].first;
}

ll solve(ll u, ll v, ll n) {
    ll lca = find_lca(u, v, n);
    auto total = add_sum(sum[u], sum[v]);
    auto lcap = add_sum(sum[lca], sum[lca]);
    auto sumlca = factors(a[lca]);
    auto subsum = sub_sum(total, lcap);
    auto path_sum = add_sum(subsum, sumlca);
    ll ans = 1;
    for(auto p : path_sum) {
        ans = mul(ans, p.second + 1);
    }
    return ans;
}

void preprocess(ll n) {
    dfs(1, -1, n, 1);
    assert(tour.size() == 2 * n);
    vector<ll> rmqarray;
    for(ll i = 0; i <= 2 * n - 1; ++i) {
        rmqarray.push_back(tour[i].second);
    }
    RMQ = SparseTable(rmqarray);
}

void test_case() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n-1; ++i) {
        ll x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    preprocess(n);
    ll q;
    cin >> q;
    for(ll i = 1; i <= q; ++i) {
        ll u, v;
        cin >> u >> v;
        cout << solve(u, v, n) << "\n";
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        reset();
        test_case();
    }
    return 0;
}

/*
2
7
1 2
1 3
1 4
3 6
3 7
5 4
8 10 15 14 12 18 9
5
1 4
2 2
5 4
2 5
3 5
5
1 2
1 3
2 4
2 5
2 6 4 3 5
2
1 4
2 2

void print_tour(ll n) {
    cout << "id: ";
    for(ll i = 1; i < tour.size(); ++i) {
        cout << tour[i].first << " ";
    }
    cout << "\n";
    cout << "dp: ";
    for(ll i = 1; i < tour.size(); ++i) {
        cout << tour[i].second << " ";
    }
    cout << "\n";
}

void print_map(unordered_map<ll, ll> &m) {
    for(auto p : m) {
        cout << p.first << "^" << p.second << " ";
    }
    cout << "\n";
}

void print_prod(ll n) {
    cout << "prod:\n";
    for(ll i = 1; i <= n; ++i) {
        cout << i << ": ";
        print_map(prod[i]);
    }
    cout << "\n";
}

void print() {
    for(ll i = 0; i < n; ++i) {
        cout << i << ": ";
        for(ll k = 0; k <= maxk; ++k) {
            cout << table[k][i] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for(ll i = 0; i < n; ++i) {
        cout << i << ": ";
        for(ll k = 0; k <= maxk; ++k) {
            cout << id[k][i] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

*/