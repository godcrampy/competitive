#include <stdio.h>
#include <stdlib.h>

int inRange(int** grid, short i, short j, short m, short n) {
  if (i < 0 || i >= m || j < 0 || j >= n) {
    return 0;
  }
  return 1;
}

int isLargerThanNeighbours(int** grid, short i, short j, short m, short n) {
  int t = grid[i][j];
  if (inRange(grid, i - 1, j - 1, m, n) && t < grid[i - 1][j - 1]) return 0;
  if (inRange(grid, i - 1, j + 1, m, n) && t < grid[i - 1][j + 1]) return 0;
  if (inRange(grid, i - 1, j, m, n) && t < grid[i - 1][j]) return 0;
  if (inRange(grid, i + 1, j - 1, m, n) && t < grid[i + 1][j - 1]) return 0;
  if (inRange(grid, i + 1, j + 1, m, n) && t < grid[i + 1][j + 1]) return 0;
  if (inRange(grid, i + 1, j, m, n) && t < grid[i + 1][j]) return 0;
  if (inRange(grid, i, j - 1, m, n) && t < grid[i][j - 1]) return 0;
  if (inRange(grid, i, j + 1, m, n) && t < grid[i][j + 1]) return 0;

  return 1;
}

void solve() {
  int m, n;
  scanf("%d %d", &m, &n);

  int* grid[m];
  for (int i = 0; i < m; i++)
    grid[i] = (int*)malloc(n * sizeof(int));

  for (short i = 0; i < m; ++i) {
    for (short j = 0; j < n; ++j) {
      scanf("%d", (*(grid + i) + j));
    }
  }

  long sum = 0;

  for (short i = 0; i < m; ++i) {
    for (short j = 0; j < n; ++j) {
      if (isLargerThanNeighbours(grid, i, j, m, n)) {
        sum += *(*(grid + i) + j);
      }
    }
  }

  printf("%ld\n", sum);
}

int main(int argc, char const* argv[]) {
  int t;
  scanf("%d", &t);
  for (int _ = 0; _ < t; ++_) {
    solve();
  }
  return 0;
}
