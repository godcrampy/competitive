#include <iostream>

using namespace std;

bool inRange(int** grid, short i, short j, short m, short n) {
  if (i < 0 || i >= m || j < 0 || j >= n) {
    return false;
  }
  return true;
}

bool isLargerThanNeighbours(int** grid, short i, short j, short m, short n) {
  int t = grid[i][j];
  if (inRange(grid, i - 1, j - 1, m, n) && t < grid[i - 1][j - 1]) return false;
  if (inRange(grid, i - 1, j + 1, m, n) && t < grid[i - 1][j + 1]) return false;
  if (inRange(grid, i - 1, j, m, n) && t < grid[i - 1][j]) return false;
  if (inRange(grid, i + 1, j - 1, m, n) && t < grid[i + 1][j - 1]) return false;
  if (inRange(grid, i + 1, j + 1, m, n) && t < grid[i + 1][j + 1]) return false;
  if (inRange(grid, i + 1, j, m, n) && t < grid[i + 1][j]) return false;
  if (inRange(grid, i, j - 1, m, n) && t < grid[i][j - 1]) return false;
  if (inRange(grid, i, j + 1, m, n) && t < grid[i][j + 1]) return false;

  return true;
}

void solve() {
  short m, n;
  cin >> m >> n;
  int** grid;
  grid = new int*[m];

  for (short i = 0; i < m; ++i) {
    grid[i] = new int[n];
  }

  for (short i = 0; i < m; ++i) {
    for (short j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  long sum = 0;

  for (short i = 0; i < m; ++i) {
    for (short j = 0; j < n; ++j) {
      if (isLargerThanNeighbours(grid, i, j, m, n)) {
        sum += grid[i][j];
      }
    }
  }

  cout << sum << '\n';
}

int main(int argc, char const* argv[]) {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    solve();
  }
  return 0;
}
