#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Graph {
 public:
  unordered_map<int, unordered_set<int>> g;
  int n;
  Graph(int n) : n(n) {
    for (int i = 0; i < n; ++i) {
      g[i] = {};
    }
  }

  void add_edge(int u, int v) {
    g[u].insert(v);
    g[v].insert(u);
  }

  vector<int> shortest_reach(int start) {
    // --start;
    vector<int> res(n, -1);
    res[start] = 0;
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
      int top = q.front();
      q.pop();
      visited[top] = true;

      for (auto neighbour : g[top]) {
        if (!visited[neighbour]) {
          visited[neighbour] = true;
          res[neighbour] = res[top] + 6;
          q.push(neighbour);
        }
      }
    }

    return res;
  }
};

int main() {
  int queries;
  cin >> queries;

  for (int t = 0; t < queries; t++) {
    int n, m;
    cin >> n;
    // Create a graph of size n where each edge weight is 6:
    Graph graph(n);
    cin >> m;
    // read and set edges
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      // add each edge to the graph
      graph.add_edge(u, v);
    }
    int startId;
    cin >> startId;
    startId--;
    // Find shortest reach from node s
    vector<int> distances = graph.shortest_reach(startId);

    for (int i = 0; i < distances.size(); i++) {
      if (i != startId) {
        cout << distances[i] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
