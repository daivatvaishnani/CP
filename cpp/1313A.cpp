#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

vvi sets = {
    {0, 0, 1},
    {0, 1, 0},
    {1, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 0},
    {1, 1, 1},
};

int ok(int mask, int a, int b, int c) {
    int qa = 0, qb = 0, qc = 0;
    int qt = 0;
    for(int i = 0; i < 7; ++i) {
        if(mask & (1 << i)) {
            qt++;
            qa += sets[i][0];
            qb += sets[i][1];
            qc += sets[i][2];
            continue;
        }
    }
    if(qa <= a && qb <= b && qc <= c) {
        return qt;
    } else {
        return INT_MIN;
    }
}

int solve(int a, int b, int c) {
    vvvi dp(11, vvi(11, vi(11, -1)));
    int ans = 0, qt;
    if(a >= 4 && b >= 4 && c >= 4) {
        return 7;
    }
    for(int i = pow(2, 7) - 1; i >= 0; --i) {
        qt = ok(i, a, b, c);
        ans = max(ans, qt);
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << "\n";
    }
    return 0;
}