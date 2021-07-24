/**
* Problem Link: https://www.codechef.com/LTIME83B/problems/SHUFFLE  
*/
#include <bits/stdc++.h>

using namespace std;

void print_vset(vector<set<int>> &vs) {
    for(int i = 0; i < vs.size(); ++i) {
        cout << i << ": ";
        for(int j : vs[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

void print_v(vector<pair<int,int>> &v) {
    for(int i = 0; i < v.size(); ++i) {
        cout << v[i].first << " ";
    }
    cout << "\n";
}

void test_case(int case_no) {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<pair<int,int>> b = a;
    sort(b.begin(), b.end());
    vector<set<int>> al, bl;
    vector<bool> visa(n, 0), visb(n, 0);
    for(int i = 0; i < n; ++i) {
        if(!visa[i]) {
            set<int> s;
            for(int j = i; j < n; j += k) {
                if(!visa[j]) {
                    s.insert(a[j].first);
                    visa[j] = 1;
                }
            }
            al.push_back(s);
        }
    }
    
    for(int i = 0; i < n; ++i) {
        if(!visb[i]) {
            set<int> s;
            for(int j = i; j < n; j += k) {
                if(!visb[j]) {
                    s.insert(b[j].first);
                    visb[j] = 1;
                }
            }
            bl.push_back(s);
        }
    }
    if(al == bl) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}