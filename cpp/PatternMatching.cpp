/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

const int maxLength = 1e4;

void printArray(vector<string> &arr) {
    for(string &s : arr) {
        cout << s << " ";
    }
    cout << "\n";
}

bool compareStrings(string &s1, string &s2) {
    if(s1.length() != s2.length()) {
        return s1.length() > s2.length();
    }
    return s1 < s2;
}

bool isPrefixMatch(string bigger, string smaller) {
    int i = 0;
    int j = 0;
    while(j < smaller.length()) {
        if(bigger[i] != smaller[j]) {
            return 0;
        }
        ++i, ++j;
    }
    return 1;
}

bool isSuffixMatch(string bigger, string smaller) {
    int i = bigger.size() - 1;
    int j = smaller.size() - 1;
    while(j >= 0) {
        if(bigger[i] != smaller[j]) {
            return 0;
        }
        --i, --j;
    }
    return 1;
}

bool isPrefixPatternFormed(vector<string> &sortedStrings) {
    bool isPatternFormed = 1;
    for(int i = 1; i < sortedStrings.size(); ++i) {
        if(!isPrefixMatch(sortedStrings[0], sortedStrings[i])) {
            isPatternFormed = 0;
        }
    }
    return isPatternFormed;
}

bool isSuffixPatternFormed(vector<string> &sortedStrings) {
    bool isPatternFormed = 1;
    for(int i = 1; i < sortedStrings.size(); ++i) {
        if(!isSuffixMatch(sortedStrings[0], sortedStrings[i])) {
            isPatternFormed = 0;
        }
    }
    return isPatternFormed;
}

vector<string> getPrefixes(vector<string> &patterns) {
    vector<string> prefixes;
    for(string s : patterns) {
        int i = 0;
        string prefix = "";
        while(i < s.length() && s[i] != '*') {
            prefix += s[i++];
        }
        if(prefix.length() > 0) {
            prefixes.push_back(prefix);
        }
    }
    sort(prefixes.begin(), prefixes.end(), compareStrings);
    return prefixes;
}

vector<string> getSuffixes(vector<string> &patterns) {
    vector<string> suffixes;
    for(string s : patterns) {
        int i = s.length() - 1;
        string suffix = "";
        while(i >= 0 && s[i] != '*') {
            suffix = s[i--] + suffix;
        }
        if(suffix.length() > 0) {
            suffixes.push_back(suffix);
        }
    }
    sort(suffixes.begin(), suffixes.end(), compareStrings);
    return suffixes;
}

vector<string> getOthers(vector<string> &patterns) {
    vector<string> others;
    for(string s : patterns) {
        int l = 0, r = s.length() - 1;
        while(l < s.length() && s[l] != '*') {
            ++l;
        }
        while(r >= 0 && s[r] != '*') {
            --r;
        }
        string other = "";
        for(int i = l; i <= r; ++i) {
            if(s[i] == '*') {
                if(other.length() > 0) {
                    others.push_back(other);
                }
                other = "";
            } else {
                other += s[i];
            }
        }
    }
    return others;
}

string satisfyAllPatterns(vector<string> &patterns) {
    string ans = "";
    int n = patterns.size();
    vector<string> prefixes = getPrefixes(patterns);
    vector<string> suffixes = getSuffixes(patterns);
    vector<string> others = getOthers(patterns);
    if(isPrefixPatternFormed(prefixes) && isSuffixPatternFormed(suffixes)) {
        if(prefixes.size() > 0) {
            ans += prefixes[0];
        }
        for(string s : others) {
            ans += s;
        }
        if(suffixes.size() > 0) {
            ans += suffixes[0];
        } 
    } else {
        ans = "*";
    }
    return ans;
}

void test_case(int case_no) {
    int n;
    cin >> n;
    string pattern;
    vector<string> patterns;
    for(int i = 0; i < n; ++i) {
        cin >> pattern;
        patterns.push_back(pattern);
    }
    pattern = satisfyAllPatterns(patterns);
    cout << "CASE #" << case_no << ": " << pattern << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}