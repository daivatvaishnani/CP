#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 5;

vector<string> str;

vector<vector<pair<ll, ll> > > graph;
vector<ll> dist;
set<pair<ll,ll> > st;

ll solve(ll n, ll k) {
    graph.resize(n);
    for(ll i = 0; i < n; ++i) {
        graph[i].clear();
    }
    for(ll i = 0; i < n; ++i) {
        for(ll j = 1; j <= k; ++j) {
            if(i + j < n && i + j >= 0 && str[i][i + j] == '1') {
                graph[i].push_back({i + j, 1});
            }
            if(i - j >= 0 && i - j < n && str[i][i - j] == '1') {
                graph[i].push_back({i - j, 1});
            }
        }
    }
    dist.resize(n, LLONG_MAX);
    for(ll i = 0; i < n; ++i) {
        dist[i] = LLONG_MAX;
    }
    dist[0] = 0;
    st.insert({dist[0], 0});
    while (!st.empty()) {
        ll v = st.begin()->second;
        st.erase(st.begin());
        for(ll i = 0; i < (ll(graph[v].size())); ++i) {
            ll prvi = graph[v][i].first;
            ll w = graph[v][i].second;
            if (dist[v] + w < dist[prvi]) {
                st.erase({dist[prvi], prvi});
                dist[prvi] = dist[v]+  w;
                st.insert({dist[prvi], prvi});
            }
        }
    }
    if(dist[n-1] == LLONG_MAX) {
        return -1;
    }
    return dist[n-1];
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        ll k, n;
        cin >> n >> k;
        str.resize(n);
        for(ll i = 0; i < n; ++i) {
            cin >> str[i];
        }
        cout << solve(n, k) << "\n";
    }
    return 0;
}