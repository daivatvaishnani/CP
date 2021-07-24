/**
* Problem Link: https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/
*/
#include <bits/stdc++.h>

using namespace std;

void insert(vector<int> &longest_two_paths, int path_length) {
    // keeping it sorted in non-increasing order
    int num_elements = longest_two_paths.size();
    if(num_elements < 2) {
        longest_two_paths.push_back(path_length);
    } else if(longest_two_paths[1] < path_length) {
        longest_two_paths[1] = path_length;
    }
    if(num_elements >= 1 && longest_two_paths[0] < longest_two_paths[1]) {
        swap(longest_two_paths[0], longest_two_paths[1]);
    }
}

int find_longest_two_paths(int node, vector<vector<int> > &graph, int &longest_distance) {
    vector<int> longest_two;
    for(int child : graph[node]) {
        insert(longest_two, find_longest_two_paths(child, graph, longest_distance) + 1);
    }
    int longest_distance_in_subtree = 0, longest_path_down = 0;
    if(longest_two.size() > 0) {
        longest_path_down = longest_two[0];
        longest_distance_in_subtree = longest_two[0];
        if(longest_two.size() > 1) {
            longest_distance_in_subtree += longest_two[1];
        }
    }
    longest_distance = max(longest_distance, longest_distance_in_subtree);
    return longest_path_down;
}

int solve_other(vector<int> &parent) {
    int n = parent.size(), root_node;
    vector<vector<int> > graph(n);
    for(int i = 0; i < n; ++i) {
        if(parent[i] != -1) {
            graph[parent[i]].push_back(i);
        } else {
            root_node = i;
        }
    }
    int longest_distance = 0, computations = 0;
    find_longest_two_paths(root_node, graph, longest_distance);
    return longest_distance;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> A = {-1, 0, 1, 1, 2, 0, 5, 0, 3, 0, 0, 2, 3, 1, 12, 14, 0, 5, 9, 6, 16, 0, 13, 4, 17, 2, 1, 22, 14, 20, 10, 17, 0, 32, 15, 34, 10, 19, 3, 22, 29, 2, 36, 16, 15, 37, 38, 27, 31, 12, 24, 29, 17, 29, 32, 45, 40, 15, 35, 13, 25, 57, 20, 4, 44, 41, 52, 9, 53, 57, 18, 5, 44, 29, 30, 9, 29, 30, 8, 57, 8, 59, 59, 64, 37, 6, 54, 32, 40, 26, 15, 87, 49, 90, 6, 81, 73, 10, 8, 16};
    cout << solve_other(A) << "\n";
    return 0;
}

/**
 * vector<int> A = {-1, 0, 1, 1, 2, 0, 5, 0, 3, 0, 0, 2, 3, 1, 12, 14, 0, 5, 9, 6, 16, 0, 13, 4, 17, 2, 1, 22, 14, 20, 10, 17, 0, 32, 15, 34, 10, 19, 3, 22, 29, 2, 36, 16, 15, 37, 38, 27, 31, 12, 24, 29, 17, 29, 32, 45, 40, 15, 35, 13, 25, 57, 20, 4, 44, 41, 52, 9, 53, 57, 18, 5, 44, 29, 30, 9, 29, 30, 8, 57, 8, 59, 59, 64, 37, 6, 54, 32, 40, 26, 15, 87, 49, 90, 6, 81, 73, 10, 8, 16};
*/