#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> s;
    vector<vector<int> > pos;
    s.resize(n);
    pos.resize(n);
    vector<pair<int, int> > pp;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        int k;
        cin >> k;
        pos[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> pos[i][j];
            --pos[i][j];
            pp.push_back(make_pair(pos[i][j], i));
        }
    }
    sort(pp.begin(), pp.end());
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < pos[i].size(); ++j) {
            maxLen = max(maxLen, pos[i][j] + (int)s[i].length());
        }
    }
    string ans = string(maxLen, 'a');
    int R = 0;
    int i = 0;
    while (i < pp.size()) {
        if (s[pp[i].second].length() + pp[i].first <= R) {
            ++i;
            continue;
        }
        if (pp[i].first > R) {
            R = pp[i].first;
        }
        int ps = R - pp[i].first;
        while (ps < s[pp[i].second].length()) {
            ans[R++] = s[pp[i].second][ps++];
        }
    }
    cout << ans << "\n";
    return 0;
}