#include <bits/stdc++.h>

using namespace std;

class Mxr {
    int upper_range;
    vector<bool> used;
public:
    Mxr(int range) {
        upper_range = range;
        used.resize(range+1, 0);
    }
    void add(int i) {
        used[i] = true;
    }
    int give(int l) {
        for(int i = l+1; i <= upper_range; ++i) {
            if(!used[i]) {
                add(i);
                return i;
            }
        }
        return -1;
    }
    void pused() {
        cout << "++++ pused ++++\n";
        for(int i = 1; i <= upper_range; ++i) {
            cout << "used " << i << ": " << used[i] << "\n";
        }
        cout << "++++ pused ++++\n";
    }
    bool exclusive() {
        for(int i = 1; i <= upper_range; ++i) {
            if(!used[i]) {
                return 0;
            }
        }
        return 1;
    }
};

vector<int> solve(vector<int> &b, int n) {
    vector<int> a(2*n+1);
    vector<int> not_possible = {-1, -1};
    Mxr mxr(2*n);
    for(int i = 1; i <= n; ++i) {
        a[2*i - 1] = b[i];
        mxr.add(b[i]);
    }
    int mex;
    for(int i = 2; i <= 2*n; i += 2) {
        mex = mxr.give(a[i-1]);
        a[i] = mex;
    }
    if(!mxr.exclusive()) {
        return not_possible;
    }
    for(int i = 1; i <= 2*n; ++i) {
        if(a[i] == -1) {
            return not_possible;
        }
    }
    return a;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> b(n+1);
        for(int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        // cout << "+++++++++++++++++++++++++++++++++++++++\n";
        vector<int> a = solve(b, n);
        for(int i = 1; i < a.size(); ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
        // cout << "+++++++++++++++++++++++++++++++++++++++\n";
    }
    return 0;
}