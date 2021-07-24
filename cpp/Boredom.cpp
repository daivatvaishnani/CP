#include <bits/stdc++.h>

using namespace std;

typedef map<int,int> hash_map;
typedef pair<int,int> pi;

hash_map cnt;

void print_ps(vector<pi> &ps) {
    for(pi &p : ps) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cnt.clear();
    int n, no, pr;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> no;
        cnt[no]++;
    }
    // sort(cnt.begin(), cnt.end());
    vector<pi> ps;
    for(auto it = cnt.begin(); it != cnt.end(); ++it) {
        ps.push_back({it->first, it->second});
    }
    print_ps(ps);
    vector<long long> f(ps.size());
    for (int i = 0; i < ps.size(); i++) {
        pr = i - 1;
        while (pr >= 0 && ps[pr].first + 1 == ps[i].first) pr--;
        f[i] = 1LL * ps[i].first * ps[i].second;
        if (pr != -1) f[i] += 1LL * f[pr]; 
        if (i != 0) {
            f[i] = max(f[i], f[i - 1]);
        }
    }
    cout << f[ps.size()-1] << "\n";
    return 0;
}