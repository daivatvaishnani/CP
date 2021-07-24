/**
* Problem Link: https://codeforces.com/problemset/problem/451/B
*/
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > getDecreasingSegments(vector<int> &a, int n) {
    vector<pair<int, int> > segments;
    int last = -1, start = -1, end = -1;
    bool started = 0;
    for(int i = 0; i < n; ++i) {
        if(started) {
            if(a[i] > last) {
                started = 0;
                end = i-1;
                segments.push_back({start, end});
            }
        } else {
            if(a[i] < last) {
                started = 1;
                start = i-1;
            }
        }
        last = a[i];
    }
    if(started) {
        end = n-1;
        segments.push_back({start, end});
    }
    return segments;
}

string solve(vector<int> &a, int n) {
    string ans;
    vector<pair<int, int> > segments = getDecreasingSegments(a, n);
    if(segments.size() == 0) {
        ans = "yes\n1 1\n";
    } else if(segments.size() == 1) {
        int start = segments[0].first;
        int end = segments[0].second;
        bool ok = 1;
        if(start - 1 >= 0 && a[end] < a[start - 1]) {
            ok = 0;
        }
        if(end + 1 < n && a[start] > a[end + 1]) {
            ok = 0;
        }
        if(ok) {
            ans = "yes\n" + to_string(start + 1) + " " + to_string(end + 1) + "\n";
        } else {
            ans = "no\n";
        }
    } else {
        ans = "no\n";
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    cout << solve(a, n) << "\n";
    return 0;
}