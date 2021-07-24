#include <bits/stdc++.h>

using namespace std;

const int maxdepth = 10;

class Axe {
public:
    int maxl, maxr;
    Axe(int x, int y) : maxl(x), maxr(y) {}
};

int find_min(vector<int> &a, int l, int r, int n) {
    int minr = 0;
    for(int i = l; i <= r; ++i) {
        if(i >= 0 && i < n && a[i] < a[minr]) {
            minr = i;
        }
    }
    return minr;
}

Axe find_axe(vector<int> &a, int i, int n) {
    int maxl = i, maxr = i, next = i;
    for(int j = 0; j < i; ++j) {
        if(a[j] > a[maxl]) {
            maxl = j;
        }
    }
    for(int j = i + 1; j < n; ++j) {
        if(a[j] > a[maxr]) {
            maxr = j;
        }
    }
    return Axe(maxl, maxr);
}

void go(vector<int> &a, int i, int n, int depth) {
    depth++;
    if(depth <= maxdepth) {
        Axe axe = find_axe(a, i, n);
        if(a[axe.maxl] > a[i] && a[axe.maxr] > a[i]) {
            int axei = axe.maxr;
            if(a[axe.maxl] < a[axe.maxr]) {
                axei = axe.maxl;
            }
            a[axei] = a[i];
            go(a, axei, n, depth);
        } else {
            int minl = find_min(a, 0, axe.maxl, n);
            int minr = find_min(a, axe.maxr, n-1, n);
            go(a, minl, n, depth);
            go(a, minr, n, depth);
        }
    }
}

void solve(vector<int> &a, int n) {
    int minr = find_min(a, 0, n, n);
    go(a, minr, n, 0);
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve(a, n);
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}