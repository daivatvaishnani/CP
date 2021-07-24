/**
* Problem Link: https://www.codechef.com/APRIL20B/problems/FCTRE
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 7;
const ll maxnum = 1e6 + 7;
const ll mod = 1e9 + 7;

double lca_time = 0, factor_time = 0, compute_time = 0;
double avg_size = 0, n_maps = 0;

// void print_time(string name, clock_t c1, clock_t c2) {
//     double time_taken = double(c2 - c1) / double(CLOCKS_PER_SEC); 
//     cerr << name << ": " << fixed  
//          << time_taken << setprecision(5); 
//     cerr << " sec " << endl; 
// }

// void print_ttc(string name, double time_taken) {
//     cerr << name << ": " << fixed  
//          << time_taken << setprecision(5); 
//     cerr << " sec " << endl; 
// }

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
};

vector<ll> graph[maxn];
ll a[maxn], d[maxn], id[maxn];
unordered_map<ll, ll> prod[maxn];
unordered_map<ll, ll> prod_arr[maxnum];
ll spf[maxnum];
vector<pair<ll, ll> > tour;

SparseTable RMQ;

ll mul(ll a, ll b) {
    return (a % mod * b % mod) % mod;
}

void sieve() {
    clock_t ss, se;
    // ss = clock();
    spf[1] = 1; 
    for (ll i = 2; i < maxnum; i++) {
        spf[i] = i;   
    }
    for (ll i = 4; i < maxnum; i += 2) {
        spf[i] = 2; 
    }
    for (ll i = 3; i * i < maxnum; i++) { 
        if (spf[i] == i) { 
            for (ll j = i * i; j < maxnum; j += i) {
                if (spf[j]==j) {
                    spf[j] = i; 
                }
            }
        } 
    }
    // se = clock();
    // print_time("sieve", ss, se);
}

unordered_map<ll, ll> add_prod(unordered_map<ll, ll> &sum1, unordered_map<ll, ll> &sum2) {
    unordered_map<ll, ll> nodesum = sum1;
    for(auto p : sum2) {
        nodesum[p.first] += p.second;
    }
    return nodesum;
}

unordered_map<ll, ll> sub_prod(unordered_map<ll, ll> &sum1, unordered_map<ll, ll> &sum2) {
    unordered_map<ll, ll> nodesum = sum1;
    for(auto p : sum2) {
        nodesum[p.first] -= p.second;
    }
    return nodesum;
}

unordered_map<ll, ll> getFactorization(ll x) { 
    unordered_map<ll, ll> ret; 
    while (x != 1) { 
        ret[spf[x]]++; 
        x = x / spf[x]; 
    }
    return ret; 
}

ll find_lca(ll u, ll v, ll n) {
    ll x = id[u], y = id[v];
    if(x > y) {
        swap(x, y);
    }
    ll low = RMQ.getMinId(x, y);
    return tour[low].first;
}

unordered_map<ll, ll> find_something(unordered_map<ll, ll> &pu, 
                                        unordered_map<ll, ll> &pv,
                                        unordered_map<ll, ll> &plca,
                                        unordered_map<ll, ll> &lca) {
    clock_t scs, sce;
    // scs = clock();
    avg_size = (avg_size * n_maps + pu.size() + pv.size() + plca.size() + lca.size()) / (n_maps + 4);
    n_maps += 4;
    unordered_map<ll, ll> left = sub_prod(pu, plca);
    unordered_map<ll, ll> right = sub_prod(pv, plca);
    unordered_map<ll, ll> product = add_prod(left, right);
    product = add_prod(product, lca);
    // sce = clock();
    // compute_time += double(sce - scs) / double(CLOCKS_PER_SEC);
    return product;
} 

ll solve(ll u, ll v, ll n) {
    // clock_t sls, sle, sfs, sfe, scs, sce;
    // sls = clock();
    ll lca = find_lca(u, v, n);
    // sle = clock();
    // lca_time += double(sle - sls) / double(CLOCKS_PER_SEC);

    // sfs = clock();
    auto plca = getFactorization(a[lca]);
    // sfe = clock();
    // factor_time += double(sfe - sfs) / double(CLOCKS_PER_SEC);
    
    unordered_map<ll, ll> product = find_something(prod[u], prod[v], prod[lca], plca);

    ll ans = 1;
    for(auto p : product) {
        ans = mul(ans, p.second + 1);
    }
    return ans;
}

void dfs(ll node, ll par, ll n, ll depth) {
    d[node] = depth;
    id[node] = tour.size();
    tour.push_back({node, d[node]});
    prod[node] = getFactorization(a[node]);
    if(par != -1) {
        prod[node] = add_prod(prod[node], prod[par]);
    }
    for(ll child : graph[node]) {
        if(d[child] == -1) {
            dfs(child, node, n, d[node] + 1);
            tour.push_back({node, d[node]});
        }
    }
}

void preprocess(ll n) {
    // clock_t ss, se;
    // ss = clock();
    dfs(1, -1, n, 1);
    assert(tour.size() == 2 * n);
    vector<ll> rmqarray;
    for(ll i = 0; i <= 2 * n - 1; ++i) {
        rmqarray.push_back(tour[i].second);
    }
    RMQ = SparseTable(rmqarray);
    // se = clock();
    // print_time("pproc", ss, se);
}

void reset(ll n) {
    clock_t ss, se;
    // ss = clock();
    memset(a, -1, sizeof(a));
    memset(d, -1, sizeof(a));
    memset(id, -1, sizeof(id));
    for(ll i = 0; i <= n; ++i) {
        prod[i].clear();
    }
    for(ll i = 0; i <= n; ++i) {
        graph[i].clear();
    }
    tour.clear();
    tour.push_back({LLONG_MAX, LLONG_MAX});
    // se = clock();
    // print_time("reset", ss, se);
}

void test_case() {
    clock_t ss, se;
    // ss = clock();
    ll n;
    cin >> n;
    reset(n);
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
    // se = clock();
    // print_time("tcase", ss, se);
    // print_ttc("lcatm", lca_time);
    // print_ttc("factm", factor_time);
    // print_ttc("cmptm", compute_time);
    // cerr << "avgmp: " << avg_size << " " << n_maps << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // clock_t ss, se; 
    // ss = clock();
    ll t;
    cin >> t;
    sieve();
    while(t--) {
        test_case();
    }
    // se = clock();
    // print_time("compl", ss, se);
    return 0;
}