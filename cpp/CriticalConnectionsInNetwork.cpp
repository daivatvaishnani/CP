/*
Problem Link: https://leetcode.com/problems/critical-connections-in-a-network/
	Constraints:
		1. 1 <= n <= 10^5
		2. n-1 <= connections.length <= 10^5
		3. connections[i][0] != connections[i][1]
		4. There are no repeated connections.
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void print_graph(vector<vector<int> > &adjList) {
        for(int i = 0; i < adjList.size(); ++i) {
            cout << i << ": ";
            for(int j : adjList[i]) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
 
    vector<vector<int> > criticalConnections(int n, vector<vector<int> > &connections) {
    	vector<vector<int> > criticalConnections;
        vector<vector<int> > networkGraph(n);
        for(auto p : connections) {
            networkGraph[p[0]].push_back(p[1]);
            networkGraph[p[1]].push_back(p[0]);
        }
        print_graph(networkGraph);
        return criticalConnections;
    }
};

void print_vector(vector<vector<int> > &arr) {
    for(vector<int> vec : arr) {
        for(int i : vec) {
            cout << i << " ";
        }
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Solution solver;
    int n = 4;
    vector<vector<int> > connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vector<vector<int> > criticalConnections = solver.criticalConnections(n, connections);
    cout << "criticalConnections:\n";
    print_vector(criticalConnections);
    return 0;
}
