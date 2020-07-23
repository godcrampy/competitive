import java.util.*;

public class Solution {
  // Complete the riddle function below.
  static long[] riddle(long[] arr) {
    int n = arr.length;
    // nextMin
    long[] nextMin = new long[n];
    long[] prevMin = new long[n];
    for (int i = 0; i < n; ++i) {
      nextMin[i] = n;
      prevMin[i] = -1;
    }
    Deque<Integer> s = new LinkedList<>();
    for (int i = 0; i < n; ++i) {
      while (!s.isEmpty() && arr[i] < arr[s.getLast()]) {
        nextMin[s.removeLast()] = i;
      }
      s.addLast(i);
    }
    s.clear();
    // prevMin
    for (int i = n - 1; i >= 0; --i) {
      while (!s.isEmpty() && arr[i] < arr[s.getLast()]) {
        prevMin[s.removeLast()] = i;
      }
      s.addLast(i);
    }

    // map: element => largestWindow
    Map<Long, Long> largestWindow = new HashMap<>();
    Map<Long, Long> windowToMinMax = new HashMap<>();
    for (int i = 0; i < n; ++i) {
      long window = nextMin[i] - prevMin[i] - 1;
      if (largestWindow.containsKey(arr[i])) {
        largestWindow.put(arr[i], Math.max(window, largestWindow.get(arr[i])));
      } else {
        largestWindow.put(arr[i], window);
      }
    }

    // reverse
    for (Map.Entry<Long, Long> e : largestWindow.entrySet()) {
      if (windowToMinMax.containsKey(e.getValue())) {
        windowToMinMax.put(e.getValue(), Math.max(e.getKey(), windowToMinMax.get(e.getValue())));
      } else {
        windowToMinMax.put(e.getValue(), e.getKey());
      }
    }

    // fill res
    long prev = -1;
    List<Long> l = new ArrayList<>();
    for (int i = n; i >= 1; --i) {
      if (windowToMinMax.containsKey((long) i)) {
        l.add(Math.max(prev, windowToMinMax.get((long) i)));
        prev = Math.max(prev, windowToMinMax.get((long) i));
      } else {
        l.add(prev);
      }
    }
    // reverse res and return
    Collections.reverse(l);
    long[] res = new long[l.size()];
    for (int i = 0; i < l.size(); ++i) {
      res[i] = l.get(i);
    }
    // res = l.toArray(res);
    return res;
  }
}
