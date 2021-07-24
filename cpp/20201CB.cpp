/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxq = 1e4;

void test_case(ll case_no) {
    ll u;
    cin >> u;
    ll maxm = pow(10, u) - 1;
    vector<pair<ll,string>> q(maxq);
    set<char> chars;
    for(ll i = 0; i < maxq; ++i) {
        cin >> q[i].first >> q[i].second;
        for(char c : q[i].second) {
            chars.insert(c);
        }
    }
    vector<string> ans(10, "x");
    // for(char c : chars) {
    //     ans += c;   
    // }
    sort(q.begin(), q.end());
    // for(int i = 0; i < maxq; ++i) {
    //     cout << q[i].first << " " << q[i].second << "\n";
    // }
    int cur = 1;
    for(int i = 0; i < maxq; ++i) {
        if(cur == 9) {
            break;
        }
        assert(cur >= q[i].first);
        if(cur > q[i].first) {
            continue;
        }
        if(q[i].second.length() > 1) {
            break;
        }
        bool placed = 0;
        for(int j = 0; j < 10; ++j) {
            if(ans[j] == q[i].second) {
                placed = 1;
                break;
            }
        }
        if(placed) {
            continue;
        }
        if(ans[cur] == "x") {
            cout << "placed " << q[i].second << " at " << cur << "\n";
            ans[cur] = q[i].second;
            cur++;
        }
    }
    string fin = "";
    for(string s : ans) {
        fin += s;
    }
    cout << "Case #" << case_no << ": " << fin << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    for(ll i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}