#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// ? Graph Boiler

class Node {
 public:
  int val;
  vector<Node *> children;
  Node(int val) : val(val) {}
};

class Graph {
 public:
  vector<Node *> nodes;
  Graph(int n) : nodes(vector<Node *>(n)) {
    for (int i = 0; i < n; ++i) {
      nodes[i] = new Node(0);
    }
  }
};

Graph matrix_to_graph(vector<vector<bool>> matrix) {
  int length = matrix.size();
  Graph res(length);

  for (int i = 0; i < length; ++i) {
    res.nodes[i]->val = i;
    for (int j = 0; j < length; ++j) {
      if (matrix[i][j]) {
        // edge from i to j
        res.nodes[i]->children.push_back(res.nodes[j]);
      }
    }
  }

  return res;
}
/*
  vector<vector<bool>> matrix = {
      {false, true, false, false, true, false, false},
      {false, false, false, true, true, false, false},
      {false, true, false, false, false, false, false},
      {false, false, true, false, true, false, false},
      {false, false, false, false, false, false, false},
      {false, false, false, false, false, false, false},
      {false, false, false, false, false, false, false}};
 */

// ? Graph Boilerplate ends;

bool bfs(Node *a, Node *b) {
  // * Time: O(number of nodes)
  // * Space: O(number of nodes)
  // is b reachable from a
  queue<Node *> to_visit;
  unordered_set<Node *> visited;
  to_visit.push(a);

  while (!to_visit.empty()) {
    Node *n = to_visit.front();
    to_visit.pop();
    visited.insert(n);

    for (Node *child : n->children) {
      if (visited.find(child) == visited.end()) {
        // child has not been visited
        if (child == b) return true;
        to_visit.push(child);
      }
    }
  }

  return false;
}

int main(int argc, char const *argv[]) {
  vector<vector<bool>> matrix = {
      {false, true, false, false, true, false, false},
      {false, false, false, true, true, false, false},
      {false, true, false, false, false, false, false},
      {false, false, true, false, true, false, false},
      {false, false, false, false, false, false, false},
      {false, false, false, false, false, false, false},
      {false, false, false, false, false, false, false}};

  Graph a = matrix_to_graph(matrix);

  cout << bfs(a.nodes[0], a.nodes[6]) << endl;
  return 0;
}
