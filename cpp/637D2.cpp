/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

long long computations = 0;

vector<pair<string, int>> rep {
    {"1110111",6},
    {"0010010",2},
    {"1011101",5},
    {"1011011",5},
    {"0111010",4},
    {"1101011",5},
    {"1101111",6},
    {"1010010",3},
    {"1111111",7},
    {"1111011",6},
};

int findnum(string &s) {
    for(int i = 0; i < rep.size(); ++i) {
        if(rep[i].first == s) {
            return i;
        }
    }
    return INT_MIN;
}

vector<vector<pair<int,int>>> pos(10000);

vector<pair<int, int>> getPos(int i) {
    return pos[i];
}

void computePos(int j, vector<string> &num) {
    int c1 = 0, def = 0;
    string repr;
    bool match = 0;
    vector<pair<int, int>> ps;
    for(auto p : rep) {
        repr = p.first;
        match = 1;
        def = 0;
        for(int i = 0; i < p.first.size(); ++i) {
            if(num[j][i] == '1' && repr[i] != '1') {
                match = 0;
                break;
            }
            if(num[j][i] != '1' && repr[i] == '1') {
                def++;
            }
        }
        if(match) {
            ps.push_back({def, findnum(repr)});
        }
    }
    sort(ps.begin(), ps.end());
    pos[j] = ps;
}

bool isValid(vector<int> &num) {
    for(int i : num) {
        if(i == INT_MIN) {
            return 0;
        }
    }
    return 1;
} 

vector<int> grtnum(vector<int> &num1, vector<int> &num2) {
    assert(num1.size() == num2.size());
    bool valid1 = isValid(num1), valid2 = isValid(num2);
    int res = 0;
    if(valid1 && !valid2) {
        res = -1;
    } else if(!valid1 && valid2) {
        res = 1;
    } else {
        for(int i = 0; i < num1.size(); ++i) {
            if(num1[i] == num2[i]) {
                continue;
            } else if(num1[i] < num2[i]) {
                res = 1;
                break;
            } else {
                res = -1;
                break;
            }
        }    
    }
    if(res == 1) {
        return num2;
    } else {
        return num1;
    }
}

vector<int> solve(int i, int n, int k, vector<string> &nums, vector<vector<vector<int>>> &dp, vector<vector<int>> &computed) {
    if(k < 0) {
        return {INT_MIN};
    }
    if(i >= n && k > 0) {
        return {INT_MIN};
    }
    if(computed[i][k] == -1) {    
        computations++;
        computed[i][k] = 1;
        if(k == 0 && i < n) {
            vector<int> ans;
            while(i < n) {
                ans.push_back(findnum(nums[i++]));
            }
            dp[i][k] = ans;
            return dp[i][k];
        }    
        if(k == 0 && i >= n) {
            dp[i][k] = {};
            return dp[i][k];
        }
        vector<int> maxans(n-i, INT_MIN), ans;
        vector<pair<int, int>> pos = getPos(i);
        for(int j = 0; j < pos.size(); ++j) {
            if(k >= pos[j].first) {
                ans = solve(i+1, n, k-pos[j].first, nums, dp, computed);
                ans.insert(ans.begin(), pos[j].second);
                if(ans.size() == n-i) {
                    maxans = grtnum(maxans, ans);
                }
            }
        }
        dp[i][k] = maxans;
    }
    return dp[i][k];
}

void test_case(int case_no) {
    int n, k;
    cin >> n >> k;
    vector<string> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        computePos(i, nums);
    }
    vector<vector<int>> computed(n+1, vector<int>(k+1, -1));
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1));
    vector<int> maxans = solve(0, n, k, nums, dp, computed);
    if(!isValid(maxans)) {
        cout << "-1";
        return;
    }
    for(int i : maxans) {
        cout << i;
    }
    cout << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}