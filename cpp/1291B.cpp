#include <bits/stdc++.h>

using namespace std;

const string pos = "Yes";
const string neg = "No";

void find_can_d(int i, vector<int> &arr, vector<bool> &can_dr, vector<bool> &can_dl) {
    int last, n = arr.size();
    last = arr[i];
    for(int j = i+1; j < n; ++j) {
        if(arr[j] >= last) {
            last = last-1;
        } else {
            last = arr[j];
        }
    }
    if(last >= 0) {
        can_dr[i] = 1;
    }
    last = arr[i];
    for(int j = i-1; j >= 0; --j) {
        if(arr[j] >= last) {
            last = last-1;
        } else {
            last = arr[j];
        }
    }
    if(last >= 0) {
        can_dl[i] = 1;
    }
}

bool ok(int i, vector<bool> &can_dr, vector<bool> &can_dl) {
    return can_dl[i] && can_dr[i];
}

string solve_slow(vector<int> &arr, int n) {
    vector<bool> can_dr(n), can_dl(n);
    int last;
    for(int i = 0; i < n; ++i) {
        find_can_d(i, arr, can_dr, can_dl);
        if(ok(i, can_dr, can_dl)) return pos;
    }
    return neg;
}

string solve(vector<int> &a, int n) {
    vector<bool> can_dr(n), can_dl(n);
    int last, max_id = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] < i) {
            break;
        }
        can_dl[i] = 1;
    }
    for(int i = n-1; i >= 0; --i) {
        if(a[i] < n-i-1) {
            break;
        }
        can_dr[i] = 1;
    }
    for(int i = 0; i < n; ++i) {
        if(can_dl[i] && can_dr[i]) {
            return pos;
        }
    }
    return neg;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << solve(arr, n) << "\n";
        // cout << solve_slow(arr, n) << "\n";
        // cout << "-----------\n";
    }
    return 0;
}