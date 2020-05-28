#include <iostream>
#include <vector>

using namespace std;

bool inRange(const vector<vector<long>>& grid, int i, int j) {
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) {
    return false;
  }
  return true;
}

bool isLargerThanNeighbours(const vector<vector<long>>& grid, int i, int j) {
  long n = grid[i][j];
  if (inRange(grid, i - 1, j - 1) && n < grid[i - 1][j - 1]) return false;
  if (inRange(grid, i - 1, j + 1) && n < grid[i - 1][j + 1]) return false;
  if (inRange(grid, i - 1, j) && n < grid[i - 1][j]) return false;
  if (inRange(grid, i + 1, j - 1) && n < grid[i + 1][j - 1]) return false;
  if (inRange(grid, i + 1, j + 1) && n < grid[i + 1][j + 1]) return false;
  if (inRange(grid, i + 1, j) && n < grid[i + 1][j]) return false;
  if (inRange(grid, i, j - 1) && n < grid[i][j - 1]) return false;
  if (inRange(grid, i, j + 1) && n < grid[i][j + 1]) return false;

  return true;
}

void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<long>> g(m, vector<long>(n));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }

  long long sum = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (isLargerThanNeighbours(g, i, j)) {
        sum += g[i][j];
      }
    }
  }

  cout << sum << endl;
}

int main(int argc, char const* argv[]) {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    solve();
  }
  return 0;
}
