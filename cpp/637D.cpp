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
    return -1;
}

vector<pair<int, int>> getPos(string num) {
    int c1 = 0, def = 0;
    string repr;
    bool match = 0;
    vector<pair<int, int>> pos;
    for(auto p : rep) {
        repr = p.first;
        match = 1;
        def = 0;
        for(int i = 0; i < p.first.size(); ++i) {
            if(num[i] == '1' && repr[i] != '1') {
                match = 0;
                break;
            }
            if(num[i] != '1' && repr[i] == '1') {
                def++;
            }
        }
        if(match) {
            pos.push_back({def, findnum(repr)});
        }
    }
    sort(pos.begin(), pos.end());
    return pos;
}

vector<int> grtnum(vector<int> &num1, vector<int> &num2) {
    assert(num1.size() == num2.size());
    int res = 0;
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
    if(res == 1) {
        return num2;
    } else {
        return num1;
    }
}

void solve(int i, int n, int k, vector<string> &nums, vector<int> num, vector<int> &maxnum) {
    if(k < 0) {
        return;
    }
    if(k == 0 && i < n) {
        return;
    }
    if(i >= n && k > 0) {
        return;
    }
    if(k == 0 && i >= n) {
        maxnum = grtnum(num, maxnum);
        return;
    }
    computations++;
    vector<pair<int, int>> pos = getPos(nums[i]);
    for(int j = 0; j < pos.size(); ++j) {
        if(k >= pos[j].first) {
            vector<int> nnum = num;
            nnum.push_back(pos[j].second);
            solve(i+1, n, k-pos[j].first, nums, nnum, maxnum);
        }
    }
}

void test_case(int case_no) {
    int n, k;
    cin >> n >> k;
    vector<string> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<int> maxnum(n, INT_MIN), num;
    solve(0, n, k, nums, num, maxnum);
    for(int i : maxnum) {
        cout << i;
    }
    cout << "\n";
    cout << computations << " computations\n";
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