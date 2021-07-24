/**
* Problem Link: https://leetcode.com/problems/trapping-rain-water/
*/
#include <bits/stdc++.h>

using namespace std;

void print_stack(stack<pair<int, int> > st) {
    cout << "-- STACK --\n";
    while(!st.empty()) {
        cout << st.top().first << " " << st.top().second << "\n";
        st.pop();
    }
    cout << "-----------\n";
}

int trap(vector<int> &height) {
    int n = height.size();
    stack<pair<int, int> > st;
    pair<int, int> top;
    int trapped = 0;
    vector<int> l(n);
    vector<int> r(n);
    for(int i = 0; i < n; ++i) {
        if(st.empty()) {
            st.push({height[i], i});
            l[i] = i;
        } else {
            top = st.top();
            if(top.first >= height[i]) {
                l[i] = top.second;
            } else {
                l[i] = i;
                st.pop();
                st.push({height[i], i});
            }
        }
    }
    while(!st.empty()) {
        st.pop();
    }
    for(int i = n-1; i >= 0; --i) {
        if(st.empty()) {
            st.push({height[i], i});
            r[i] = i;
        } else {
            top = st.top();
            if(top.first >= height[i]) {
                r[i] = top.second;
            } else {
                r[i] = i;
                st.pop();
                st.push({height[i], i});
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        trapped += min(height[l[i]], height[r[i]]) - height[i];
    }
    return trapped;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(a) << "\n";
    return 0;
}