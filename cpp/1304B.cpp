#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    string st;
    cin >> n >> m;
    vector<string> specials;
    unordered_set<string> s(n);
    unordered_map<string, bool> taken;
    for(int i = 0; i < n; ++i) {
        cin >> st;
        s.insert(st);
        taken[st] = 0;
    }
    // for(string st : s) {
    //     cout << st << "\n";1
    // }
    string pre = "", suf = "";
    for(string str : s) {
        st = str;
        reverse(st.begin(), st.end());
        if(str != st) {
            if(s.find(st) != s.end() && !taken[str] && !taken[st]) {
                taken[str] = 1;
                taken[st] = 1;
                pre += str;
                suf = st + suf;
            }
        } else {
            specials.push_back(str);
        }
    }
    // cout << pre << "\n";
    // cout << suf << "\n";
    string longest = "";
    // cout << longest.length() << " --\n";
    for(string st : specials) {
        if(st.length() > longest.length()) {
            longest = st;
        }
    }
    int len = pre.length() + longest.length() + suf.length();
    cout << len << "\n";
    cout << pre << longest << suf << "\n";
    return 0;
}