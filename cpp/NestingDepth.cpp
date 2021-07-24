/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

string solve(string s) {
    string ans = "";
    s = "0" + s;
    s = s + "0";
    int cd, pd;
    for(int i = 1; i < s.length(); ++i) {
        cd = s[i]-'0', pd = s[i-1]-'0';
        if(cd > pd) {
            ans += string(cd-pd, '(');
        } else if(cd < pd) {
            ans += string(pd-cd, ')');
        }
        if(i != s.length() - 1) {
            ans += s[i];
        }
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        string s;
        cin >> s;
        string ans = solve(s);
        cout << "CASE #" << i << ": " << ans << "\n";
    }
    return 0;
}

/*
211221321

0
{
    {
        2
    }
    1
    1
    {
        2
        2
    }
    1
    {
        {
            3
        }
        2
    }
    1
}
0

((2)11(22)1((3)2)1)
*/
