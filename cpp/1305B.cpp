/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void solve(string s) {
    int n = s.length();
    vector<int> removed;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '(') {
            for(int j = n-1; j > i; --j) {
                if(s[j] == ')') {
                    s[i] = s[j] = '-';
                    removed.push_back(i);
                    removed.push_back(j);
                    break;
                }
            }
        }
    }
    // cout << s << "\n";
    sort(removed.begin(), removed.end());
    if(removed.empty()) {
        cout << "0\n";
        return;
    }
    cout << "1\n" << removed.size() << "\n";
    for(int i : removed) {
        cout << i+1 << " ";
    }
    cout << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    solve(s);
    return 0;
}