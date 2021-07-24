/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

void insert(unordered_set<int> &s, int val) {
    if(s.find(val) == s.end()) {
        s.insert(val);
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> tp(n);
        unordered_map<int, int> m;
        int c = 1;
        for(int i = 0; i < n; ++i) {
            cin >> tp[i];
            if(m.find(tp[i]) == m.end()) {
                m[tp[i]] = c;
                c++;
            }
        }
        if(m.size() < 3) {
            cout << m.size() << "\n";
            for(int i = 0; i < n; ++i) {
                cout << m[tp[i]] << " ";
            }
            cout << "\n";
            continue;
        }
    }
    return 0;
}

/*
4
5
1 2 1 2 2
6
1 2 2 1 2 2
5
1 2 1 2 3
9
5 5 1 15 1 5 5 1 1
1 1 2 1  2 1 1 2 2
*/