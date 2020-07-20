#include <bits/stdc++.h>

using namespace std;

int bfsRegion(vector<vector<int>> &grid, int i, int j, int maxRegion) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() ||
      grid[i][j] == 0) {
    return maxRegion;
  }

  grid[i][j] = 0;
  ++maxRegion;
  maxRegion = bfsRegion(grid, i + 1, j, maxRegion);
  maxRegion = bfsRegion(grid, i - 1, j, maxRegion);
  maxRegion = bfsRegion(grid, i + 1, j + 1, maxRegion);
  maxRegion = bfsRegion(grid, i - 1, j + 1, maxRegion);
  maxRegion = bfsRegion(grid, i, j + 1, maxRegion);
  maxRegion = bfsRegion(grid, i + 1, j - 1, maxRegion);
  maxRegion = bfsRegion(grid, i - 1, j - 1, maxRegion);
  maxRegion = bfsRegion(grid, i, j - 1, maxRegion);

  return maxRegion;
}

// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
  int maxSoFar = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      maxSoFar = max(maxSoFar, bfsRegion(grid, i, j, 0));
    }
  }

  return maxSoFar;
}
