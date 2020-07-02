#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

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

// ! IMP Topological sort & Finding loops in Directed Disconnected Graphs

void topological_sort(Node *next, stack<Node *> &s,
                      unordered_set<Node *> &to_visit) {
  if (to_visit.find(next) == to_visit.end()) return;
  to_visit.erase(next);

  for (auto n : next->children) {
    topological_sort(n, s, to_visit);
  }

  s.push(next);
}

vector<int> build_deps(Graph g) {
  // * Time: O(n)
  // * Space: O(n)
  unordered_set<Node *> to_visit(g.nodes.begin(), g.nodes.end());
  stack<Node *> s;
  while (!to_visit.empty()) {
    topological_sort(*to_visit.begin(), s, to_visit);
  }
  vector<int> res;
  while (!s.empty()) {
    res.push_back(s.top()->val);
    s.pop();
  }
  return res;
}

bool dfs(Node *next, unordered_set<Node *> &visited_stack,
         unordered_set<Node *> &to_visit) {
  if (visited_stack.find(next) != visited_stack.end()) {
    // found in stack => cycle
    return true;
  }
  if (to_visit.find(next) == to_visit.end()) {
    // already visited
    return false;
  }
  to_visit.erase(next);
  visited_stack.insert(next);
  for (auto n : next->children) {
    if (dfs(n, visited_stack, to_visit)) return true;
  }
  visited_stack.erase(next);
  return false;
}

bool has_cycle(Graph g) {
  // * Time: O(n)
  // * Space: O(n)
  unordered_set<Node *> s(g.nodes.begin(), g.nodes.end());

  while (!s.empty()) {
    unordered_set<Node *> visited_stack;
    if (dfs(*s.begin(), visited_stack, s)) return true;
  }

  return false;
}

int main(int argc, char const *argv[]) {
  vector<vector<bool>> matrix = {
      {false, false, false, true, false, false},
      {false, false, false, true, false, false},
      {false, false, false, false, false, false},
      {false, false, true, false, false, false},
      {false, false, false, false, false, false},
      {true, true, false, false, false, false},
  };

  Graph g = matrix_to_graph(matrix);
  if (has_cycle(g)) {
    cout << "HAS CYCLE" << endl;
  } else {
    auto v = build_deps(g);
    for (auto n : v) {
      cout << n << " ";
    }
    cout << endl;
  }

  return 0;
}
