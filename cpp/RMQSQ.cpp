/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

class SparseTable {
    int maxk, n;
    vector<vector<int> > table;
    vector<vector<int> > id;
    vector<int> a;
    
    void construct() {
        for(int i = 0; i < n; ++i) {
            table[0][i] = a[i];
            id[0][i] = i;
        }
        for(int k = 1; k <= maxk; ++k) {
            for(int i = 0; i < n; ++i) {
                if(i + (1 << k) - 1 < n) {
                    table[k][i] = min(table[k-1][i], table[k-1][i + (1 << (k-1))]);
                    id[k][i] = (table[k][i] == table[k-1][i]) ? id[k-1][i] : id[k-1][i + (1 << (k-1))];
                }
            }
        }
    }
public:
    SparseTable() {

    }

    SparseTable(vector<int> &arr) {
        a = arr;
        n = a.size();
        maxk = log2(n);
        table.resize(maxk + 1);
        id.resize(maxk + 1);
        for(int k = 0; k <= maxk; ++k) {
            table[k].resize(n, INT_MAX);
            id[k].resize(n, -1);
        }
        construct();
    }

    int getMin(int l, int r) {
        int len = (r - l + 1);
        int k = log2(len);
        int m = r - (1 << k) + 1;
        int rmin = min(table[k][l], table[k][m]);
        return rmin;
    }

    int getMinId(int l, int r) {
        int len = (r - l + 1);
        int k = log2(len);
        int m = r - (1 << k) + 1;
        int rmin = min(table[k][l], table[k][m]);
        int minId = (rmin == table[k][l]) ? id[k][l] : id[k][m];
        return minId;
    }

    void print() {
        for(int i = 0; i < n; ++i) {
            cout << i << ": ";
            for(int k = 0; k <= maxk; ++k) {
                cout << table[k][i] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        for(int i = 0; i < n; ++i) {
            cout << i << ": ";
            for(int k = 0; k <= maxk; ++k) {
                cout << id[k][i] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

void test_case() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SparseTable RMQ(a);
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << RMQ.getMin(l, r) << "\n";
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while(t--) {
        test_case();
    }
    return 0;
}