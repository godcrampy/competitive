import java.util.*;

public class Solution {
  static class Point {
    public int x;
    public int y;
    public int distance;

    Point(int x, int y, int distance) {
      this.x = x;
      this.y = y;
      this.distance = distance;
    }
  }

  // Complete the minimumMoves function below.
  static int minimumMoves(String[] grid, int startX, int startY, int goalX, int goalY) {
    int xSize = grid.length;
    int ySize = grid[0].length();
    boolean[][] visited = new boolean[xSize][ySize];
    for (int i = 0; i < xSize; ++i) {
      Arrays.fill(visited[i], false);
    }

    Deque<Point> q = new LinkedList<>();
    q.addLast(new Point(startX, startY, 0));
    visited[startX][startY] = true;

    while (!q.isEmpty()) {
      Point top = q.removeFirst();

      // xleft
      int minX = top.x;
      int maxX = top.x;
      while (minX - 1 >= 0 && grid[minX - 1].charAt(top.y) != 'X') {
        --minX;
      }

      while (maxX + 1 < xSize && grid[maxX + 1].charAt(top.y) != 'X') {
        ++maxX;
      }

      for (int i = minX; i <= maxX; ++i) {
        if (!visited[i][top.y]) {
          if (i == goalX && top.y == goalY) {
            return top.distance + 1;
          }
          visited[i][top.y] = true;
          q.addLast(new Point(i, top.y, top.distance + 1));
        }
      }

      int minY = top.y;
      int maxY = top.y;
      while (minY - 1 > 0 && grid[top.x].charAt(minY - 1) != 'X') {
        --minY;
      }

      while (maxY + 1 < ySize && grid[top.x].charAt(maxY + 1) != 'X') {
        ++maxY;
      }

      for (int i = minY; i <= maxY; ++i) {
        if (!visited[top.x][i]) {
          if (i == goalY && top.x == goalX) {
            return top.distance + 1;
          }
          visited[top.x][i] = true;
          q.addLast(new Point(top.x, i, top.distance + 1));
        }
      }
    }

    return -1;
  }
}
