import java.util.*;

public class Solution {
  // Complete the roadsAndLibraries function below.
  static long roadsAndLibraries(int n, int c_lib, int c_road, int[][] cities) {
    if (c_lib <= c_road) {
      return (long) c_lib * (long) n;
    }

    // get number of islands
    Map<Integer, Set<Integer>> neighbours = new HashMap<>();
    // Set<Integer> toVisit = new HashSet<>();

    for (int i = 1; i <= n; ++i) {
      neighbours.put(i, new HashSet<Integer>());
      // toVisit.add(i);
    }

    for (int[] edge : cities) {
      neighbours.get(edge[0]).add(edge[1]);
      neighbours.get(edge[1]).add(edge[0]);
    }

    long numberOfIslands = 0;
    boolean[] visited = new boolean[n + 1];
    Arrays.fill(visited, false);

    for (int i = 1; i <= n; ++i) {
      if (!visited[i]) {
        ++numberOfIslands;
        Queue<Integer> q = new ArrayDeque<>();
        q.add(i);
        while (!q.isEmpty()) {
          int top = q.remove();
          visited[top] = true;
          for (int j : neighbours.get(top)) {
            if (!visited[j]) {
              q.add(j);
            }
          }
        }
      }
    }

    return numberOfIslands * (long) c_lib + (n - numberOfIslands) * (long) c_road;
  }
}
