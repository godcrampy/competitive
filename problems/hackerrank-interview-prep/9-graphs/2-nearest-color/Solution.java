import java.util.*;

public class Solution {
  // Complete the findShortest function below.

  /*
   * For the unweighted graph, <name>:
   *
   * 1. The number of nodes is <name>Nodes.
   * 2. The number of edges is <name>Edges.
   * 3. An edge exists between <name>From[i] to <name>To[i].
   *
   */
  static int findShortest(int graphNodes, int[] graphFrom, int[] graphTo, long[] ids, int val) {
    // solve here
    Map<Integer, Set<Integer>> neighbours = new HashMap<>();

    for (int i = 0; i < graphNodes; ++i) {
      neighbours.put(i, new HashSet<Integer>());
    }

    for (int i = 0; i < graphFrom.length; ++i) {
      neighbours.get(graphFrom[i] - 1).add(graphTo[i] - 1);
      neighbours.get(graphTo[i] - 1).add(graphFrom[i] - 1);
    }

    int minDistance = Integer.MAX_VALUE;

    for (int i = 0; i < graphNodes; ++i) {
      if (ids[i] == val) {
        // do bfs
        int distance = 0;
        boolean[] visited = new boolean[graphNodes];
        Arrays.fill(visited, false);
        Queue<Integer> q = new ArrayDeque<>();
        q.add(i);
        boolean found = false;
        while (!q.isEmpty()) {
          int top = q.remove();
          visited[top] = true;
          ++distance;
          for (int neighbour : neighbours.get(top)) {
            if (!visited[neighbour]) {
              if (ids[neighbour] == val) {
                // found
                found = true;
                minDistance = Math.min(minDistance, distance);
              }
              q.add(neighbour);
            }
          }
          if (found) {
            break;
          }
        }
      }
    }

    return minDistance == Integer.MAX_VALUE ? -1 : minDistance;
  }
}
