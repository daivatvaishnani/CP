/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

#define start first
#define finish second

int find_turn(vector<int> &ft, pair<int, int> &act) {
    int turn = -1;
    for(int i = 0; i < 2; ++i) {
        if(ft[i] <= act.start) {
            turn = i;
            break;
        }
    }
    return turn;
}

string solve(vector<pair<pair<int, int>, int> > &act, int n) {
    sort(act.begin(), act.end());
    string ans(n, '-');
    vector<int> ft(2, 0);
    int possible = 1, turn;
    for(int i = 0; i < n; ++i) {
        turn = find_turn(ft, act[i].first);
        if(turn >= 0) {
            ft[turn] = act[i].first.finish;
            ans[act[i].second] = (turn & 1 ? 'C' : 'J');
        }
        else {
            possible = 0;
            break;
        }
    }
    if(!possible) {
        ans = "IMPOSSIBLE";
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        int n;
        cin >> n;
        vector<pair<pair<int, int>, int> > act(n);
        for(int i = 0; i < n; ++i) {
            act[i].second = i;
            cin >> act[i].first.start >> act[i].first.finish;
        }
        string ans = solve(act, n);
        cout << "CASE #" << i << ": " << ans << "\n";
    }
    return 0;
}