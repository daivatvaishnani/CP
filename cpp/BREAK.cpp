/**
* Problem Link: https://www.codechef.com/MARCH20B/problems/BREAK
*/
#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void insert_in_set(unordered_set<int> &s, int val) {
    if(s.find(val) == s.end()) {
        s.insert(val);
    }
}

string solve(vector<int> &a, vector<int> &b, int s) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    print(a);
    print(b);
    unordered_set<int> played;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] < b[i]) {
            if(i == 0 || played.find(a[i]) != played.end()) {
                insert_in_set(played, a[i]);
                insert_in_set(played, b[i]);
            } else {
                return "NO";
            }
        } else {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, s;
    cin >> t >> s;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        cout << solve(a, b, s) << "\n";
    }
    return 0;
}