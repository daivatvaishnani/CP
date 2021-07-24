#include <bits/stdc++.h>

using namespace std;

const int N = 100;

vector<int> graph[N];
int color[N];
bool cycle;

void add_edge(int a, int b) {
  graph[a].push_back(b);
}

void remove_edge(int a, int b) {
  graph[a].erase(find(graph[a].begin(), graph[a].end(), b));
}

void visit_node(int par) {
  if(color[par] == 1) {
    color[par] = 2;
    for(int child : graph[par]) {
      if(color[child] == 1) {
        visit_node(child);
      }
      else if(color[child] == 2) {
        cycle = true;
        return;
      }
    }
    color[par] = 3;
  }
}

void check_cycle() {
  cycle = false;
  for(int i = 0; i < N; ++i) {
    color[i] = 1;
  }
  for(int i = 0; i < N; ++i) {
    if(color[i] == 1) {
      visit_node(i);
    }
  }
}

void process(string a, string b) {
  if(a.size() == 1 && (int) a[0] >= 97 && (int) a[0] <= 122) {
    // PROCESS
    add_edge(a[0] - 47, stoi(b)); // PROCESS from 50-76
  }
  else {
    // RESOURCE
    add_edge(stoi(a), b[0] - 47); // RESOURCE from 1-26
  }
  check_cycle();
  cout << a << " " << b << "\n";
  if(cycle) {
    cout << "This forms a cycle!\n";
    if(a.size() == 1 && (int) a[0] >= 97 && (int) a[0] <= 122) {
      // PROCESS
      remove_edge(a[0] - 47, stoi(b)); // PROCESS from 50-76
    }
    else {
      // RESOURCE
      remove_edge(stoi(a), b[0] - 47); // RESOURCE from 1-26
    }
  }
}

int main() {
  freopen("in1", "r", stdin);
  freopen("out1", "w", stdout);
  string a, b;
  string line;
  stringstream ss;
  while (std::getline(cin, line)) {
    ss << line << " ";
  }
  while(ss >> a >> b) {
    process(a, b);
  }
}
