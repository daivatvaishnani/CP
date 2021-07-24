/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string &s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    return rev_s == s;
}

string longestPalindrome(string s) {
    int n = s.length();
    if(n <= 1) {
        return s;
    }
    int best_len = 0, len, j;
    string best_str;
    for(int i = 0; i < n; ++i) {
        j = 0;
        while(i - j >= 0 && i + j < n && s[i - j] == s[i + j]) {
            j++;
        }
        j--;
        len = 2 * j + 1;
        if(len > best_len) {
            best_len = len;
            best_str = s.substr(i - j, best_len);
        }
    }
    for(int i = 0; i < n-1; ++i) {
        j = 0;
        while(i - j >= 0 && i + 1 + j < n && s[i - j] == s[i + 1 + j]) {
            j++;
        }
        j--;
        len = 2 * j + 2;
        if(len > best_len) {
            best_len = len;
            best_str = s.substr(i - j, best_len);
        }
    }
    return best_str;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    cout << longestPalindrome(s) << "\n";
    return 0;
}