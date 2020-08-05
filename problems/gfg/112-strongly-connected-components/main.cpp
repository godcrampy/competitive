
/*  Function to find the number of strongly connected components
 *   using Kosaraju's algorithm
 *   V: number of vertices
 *   adj[]: array of vectors to represent graph
 */

void fillOrder(vector<int> g[], bool visited[], int n, int i, stack<int> &s) {
  visited[i] = true;

  for (int j : g[i]) {
    if (!visited[j]) fillOrder(g, visited, n, j, s);
  }

  s.push(i);
}

vector<vector<int>> transpose(vector<int> g[], int n) {
  vector<vector<int>> res(n);

  for (int i = 0; i < n; ++i) {
    for (int j : g[i]) {
      res[j].push_back(i);
    }
  }

  return res;
}

void dfs(int i, vector<vector<int>> &t, bool visited[]) {
  visited[i] = true;
  for (auto j : t[i]) {
    if (!visited[j]) {
      dfs(j, t, visited);
    }
  }
}

int kosaraju(int n, vector<int> g[]) {
  // dfs and make stack
  stack<int> s;
  bool visited[n];
  fill_n(visited, n, false);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      fillOrder(g, visited, n, i, s);
    }
  }

  // reverse graph
  auto t = transpose(g, n);
  fill_n(visited, n, false);
  // dfs and count

  int count = 0;

  while (!s.empty()) {
    int top = s.top();
    s.pop();

    if (!visited[top]) {
      visited[top] = true;
      ++count;
      dfs(top, t, visited);
    }
  }

  return count;
}
