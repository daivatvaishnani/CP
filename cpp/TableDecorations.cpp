#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> combs = {
    "aab",
    "aac",
    "abb",
    "abc",
    "acc",
    "bbc",
    "bcc"
};

vector<int> cnt;

ll solve(ll a, ll b, ll c) {
    // how many triplets can be formed such that all 3 should not be the same!
    ll ans = -1;
    
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << "\n";
    return 0;
}