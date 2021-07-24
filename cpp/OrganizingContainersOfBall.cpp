/**
* Problem Link: 
*/              
#include <bits/stdc++.h>

using namespace std;

bool organizeContainers(vector<vector<int>> &containers) {
        
}

string organizingContainers(vector<vector<int>> &containers) {
    bool possible = organizeContainers(containers);
    string answer = "Impossible";
    if(possible) {
        answer = "Possible";
    }
    return answer;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<int>> container = {{1, 4}, {2, 3}};
    cout << organizingContainers(container);
    return 0;
}