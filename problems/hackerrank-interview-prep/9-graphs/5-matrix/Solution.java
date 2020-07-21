import java.util.*;

public class Solution {
  static int root(int[] ds, int a) {
    while (a != ds[a]) {
      a = ds[a];
    }
    return a;
  }

  static void union(int[] ds, int a, int b) {
    int ra = root(ds, a);
    int rb = root(ds, b);

    if (ra < rb) {
      ds[rb] = ra;
    } else {
      ds[ra] = rb;
    }
  }

  static boolean find(int[] ds, int a, int b) {
    return root(ds, a) == root(ds, b);
  }

  // Complete the minTime function below.
  static int minTime(int[][] roads, int[] machines) {
    int n = roads.length + 1;
    int[] ds = new int[n];
    for (int i = 0; i < n; ++i) {
      ds[i] = i;
    }

    for (int m : machines) {
      union(ds, m, machines[0]);
    }

    Arrays.sort(roads, new SortByRoad());

    int cost = 0;
    for (int[] v : roads) {
      if (find(ds, v[0], machines[0]) && find(ds, v[1], machines[1])) {
        cost += v[2];
      } else {
        union(ds, v[0], v[1]);
      }
    }

    return cost;
  }

  static class SortByRoad implements Comparator<int[]> {
    public int compare(int[] a, int[] b) {
      return b[2] - a[2];
    }
  }
}
