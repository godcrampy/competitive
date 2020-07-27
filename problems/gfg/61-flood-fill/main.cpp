#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void floodFill(vector<vector<int>>& grid, int i, int j, int from, int to) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() ||
      grid[i][j] != from) {
    return;
  }

  grid[i][j] = to;

  floodFill(grid, i + 1, j, from, to);
  floodFill(grid, i - 1, j, from, to);
  floodFill(grid, i, j + 1, from, to);
  floodFill(grid, i, j - 1, from, to);
}

void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> g(m, vector<int>(n));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }

  int x, y, to;
  cin >> x >> y >> to;

  floodFill(g, x, y, g[x][y], to);

  for (auto v : g) {
    for (int i : v) {
      cout << i << " ";
    }
  }

  cout << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
