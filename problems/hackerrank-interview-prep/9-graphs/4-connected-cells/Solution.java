import java.math.*;

public class Solution {
  static int bfsRegion(int[][] grid, int i, int j, int maxRegion) {
    if (i < 0 || j < 0 || i >= grid.length || j >= grid[i].length || grid[i][j] == 0) {
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
  static int maxRegion(int[][] grid) {
    int maxSoFar = 0;
    for (int i = 0; i < grid.length; ++i) {
      for (int j = 0; j < grid[i].length; ++j) {
        maxSoFar = Math.max(maxSoFar, bfsRegion(grid, i, j, 0));
      }
    }

    return maxSoFar;
  }
}
