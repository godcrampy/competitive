import java.math.*;
import java.util.*;

public class Solution {
  static int root(int[] ds, int i) {
    while (i != ds[i]) {
      i = ds[i];
    }
    return i;
  }

  static int join(int[] ds, int[] maxGroup, int i, int j, int maxSoFar) {
    int ri = root(ds, i);
    int rj = root(ds, j);

    if (ri == rj) {
      return maxSoFar;
    }

    if (ri < rj) {
      // rj is no more root
      ds[rj] = ri;
      maxGroup[ri] += maxGroup[rj];
      return Math.max(maxGroup[ri], maxSoFar);
    }

    ds[ri] = rj;
    maxGroup[rj] += maxGroup[ri];
    return Math.max(maxGroup[rj], maxSoFar);
  }

  // Complete the maxCircle function below.
  static int[] maxCircle(int[][] queries) {
    Set<Integer> store = new TreeSet<>();
    Map<Integer, Integer> m = new HashMap<>();

    for (int[] q : queries) {
      store.add(q[0]);
      store.add(q[1]);
    }

    int x = 0;
    for (int n : store) {
      m.put(n, x++);
    }

    for (int[] q : queries) {
      q[0] = m.get(q[0]);
      q[1] = m.get(q[1]);
    }

    int peopleCount = store.size();
    int[] ds = new int[peopleCount];
    int[] maxGroup = new int[peopleCount];

    for (int i = 0; i < peopleCount; ++i) {
      ds[i] = i;
      maxGroup[i] = 1;
    }
    int maxSoFar = -1;
    int[] res = new int[queries.length];

    for (int i = 0; i < queries.length; ++i) {
      int temp = join(ds, maxGroup, queries[i][0], queries[i][1], maxSoFar);
      maxSoFar = Math.max(maxSoFar, temp);
      res[i] = temp;
    }

    return res;
  }
}
