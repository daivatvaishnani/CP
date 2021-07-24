/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> getCompassNeighbours(vector<vector<ll>> &arr, vector<vector<ll>> &status, 
                                    ll rows, ll cols, ll i, ll j) {
    vector<ll> neighbours;
    for(ll cr = i+1; cr < rows; ++cr) {
        if(status[cr][j] != -1) {
            neighbours.push_back(arr[cr][j]);
            break;
        }
    }
    for(ll cr = i-1; cr >= 0; --cr) {
        if(status[cr][j] != -1) {
            neighbours.push_back(arr[cr][j]);
            break;
        }
    }
    for(ll cj = j+1; cj < cols; ++cj) {
        if(status[i][cj] != -1) {
            neighbours.push_back(arr[i][cj]);
            break;
        }
    }
    for(ll cj = j-1; cj >= 0; --cj) {
        if(status[i][cj] != -1) {
            neighbours.push_back(arr[i][cj]);
            break;
        }
    }
    return neighbours;
}

pair<ll,ll> simulateRound(vector<vector<ll>> &arr, vector<vector<ll>> &status, 
                                ll rows, ll cols, bool shouldEliminate = true) {
    ll eliminated = 0, interestLevel = 0;
    for(ll i = 0; i < rows; ++i) {
        for(ll j = 0; j < cols; ++j) {
            if(status[i][j] == 0) {
                interestLevel += arr[i][j];
                if(shouldEliminate) {
                    vector<ll> neighbours = getCompassNeighbours(arr, status, rows, cols, i, j);
                    if(neighbours.size() > 0) {
                        double avgSkill = 0.0;
                        for(ll i : neighbours) {
                            avgSkill += (double)i;
                        }
                        avgSkill /= double(neighbours.size());
                        if(avgSkill > (double)arr[i][j]) {
                            eliminated++;
                            interestLevel -= arr[i][j];
                            status[i][j] = 1;
                        }
                    }
                }
            }
        }
    }
    if(shouldEliminate) {
        for(ll i = 0; i < rows; ++i) {
            for(ll j = 0; j < cols; ++j) {
                if(status[i][j] == 1) {
                    status[i][j] = -1;
                }
            }
        }
    }
    
    return {eliminated, interestLevel};
}

ll findInterestLevel(vector<vector<ll>> &arr, ll rows, ll cols) {
    vector<vector<ll>> status(rows, vector<ll> (cols));
    ll numRounds = 5, interestLevel = 0;
    pair<ll,ll> simStats = simulateRound(arr, status, rows, cols, false);
    interestLevel += simStats.second;
    while(1) {
        simStats = simulateRound(arr, status, rows, cols);
        if(simStats.first > 0) {
            interestLevel += simStats.second;
        } else {
            break;
        }
    }
    return interestLevel;
}

void test_case(ll case_no) {
    ll rows, cols;
    cin >> rows >> cols;
    vector<vector<ll>> arr(rows, vector<ll> (cols));
    for(ll i = 0; i < rows; ++i) {
        for(ll j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }
    ll interestLevel = findInterestLevel(arr, rows, cols);
    cout << "Case #" << case_no << ": " << interestLevel << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    for(ll i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}