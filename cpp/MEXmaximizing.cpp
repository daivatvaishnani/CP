#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x, no;
    cin >> n >> x;
    vector<int> cnt(x, 0);
    set<pair<int, int> > st;
    for(int i = 0; i < x; ++i) {
        st.insert({0, i});
        cnt[i] = 0;
    }
    for(int i = 0; i < n; ++i) {
        cin >> no;
        no %= x;
        st.erase({cnt[no], no});
        cnt[no]++;
        st.insert({cnt[no], no});
        cout << x * st.begin()->first + st.begin()->second << "\n";
    }
    return 0;
}