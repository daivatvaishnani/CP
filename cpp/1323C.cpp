/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

int solve(int n, string s) {
    n = s.length();
    int open = 0, close = 0, balanced = 1, time = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '(') open++;
        else close++;
    }
    if(open != close) {
        return -1;
    }
    stack<char> st;
    close = 0, open = 0, balanced = 1;
    // cout << s << "\n";
    for(int i = 0; i < n; ++i) {
        if(balanced) {
            // cout << "balanced ";
            if(s[i] == '(') {
                // cout << "pushed (";
                st.push(s[i]);
            } else {
                if(!st.empty() && st.top() == '(') {
                    // cout << "popped " << st.top();
                    st.pop();
                } else {
                    // cout << "unbalanced ";
                    balanced = 0;
                    close = 1;
                }
            }
        } else {
            if(s[i] == '(') open++;
            else close++;
            // cout << "unbalanced " << open << " " << close << " "; 
            if(open == close) {
                time += open + close;
                // cout << "balanced " << time;
                close = 0;
                open = 0;
                balanced = 1;
            }
        }
        // cout << "\n";
    }
    return time;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    cout << solve(n, s) << "\n";
    return 0;
}