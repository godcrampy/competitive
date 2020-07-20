#include <bits/stdc++.h>

using namespace std;

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to,
                 vector<long> ids, int val) {
  // solve here
  unordered_map<int, unordered_set<int>> neighbours;

  for (int i = 0; i < graph_from.size(); ++i) {
    neighbours[graph_from[i] - 1].insert(graph_to[i] - 1);
    neighbours[graph_to[i] - 1].insert(graph_from[i] - 1);
  }

  int minDistance = INT_MAX;

  for (int i = 0; i < graph_nodes; ++i) {
    if (ids[i] == val) {
      // do bfs and find min distance
      vector<bool> visited(graph_nodes, false);
      queue<int> q;
      q.push(i);
      int distance = 0;
      while (!q.empty()) {
        ++distance;
        int top = q.front();
        q.pop();
        visited[top] = true;
        bool found = false;
        for (int neighbour : neighbours[top]) {
          if (!visited[neighbour]) {
            if (ids[neighbour] == val) {
              // found a color
              found = true;
              minDistance = min(minDistance, distance);
              break;
            }
            q.push(neighbour);
          }
        }
        if (found) {
          break;
        }
      }
    }
  }
  return minDistance == INT_MAX ? -1 : minDistance;
}
