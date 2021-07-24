// https://leetcode.com/problems/valid-parenthesis-string/
#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << ":" << (x) << " | "

class Solution {
public:
    bool checkValidString(string s) {
        bool validity = true;
        int lo = 0, hi = 0;
        for (char c : s) {
            switch (c) {
                case '(':
                    lo++;
                    hi++;
                    break;
                case ')':
                    lo--;
                    hi--;
                    break;
                case '*':
                    hi++;
                    break;
                default:
                    break;
            }
        }
        validity = (lo <= 0 && hi >= 0); 
        cout << s << " " << (validity ? "valid" : "invalid") << "\n";
        return validity;
    }
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("in", "r", stdin);
    string input = "(*))";
    Solution solution;
    solution.checkValidString(input);
    return 0;
}

