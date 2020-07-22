import java.util.*;

public class Solution2 {
  // Complete the largestRectangle function below.
  static long largestRectangle(int[] h) {
    Deque<Integer> stk = new LinkedList<>();
    long maxArea = -1;
    int i = 0;

    while (i < h.length) {
      if (stk.isEmpty() || h[i] >= h[stk.getLast()]) {
        stk.addLast(i++);
      } else {
        int top = stk.removeLast();
        if (stk.isEmpty()) {
          maxArea = Math.max(maxArea, (long) h[top] * i);
        } else {
          maxArea = Math.max(maxArea, (long) h[top] * (i - stk.getLast() - 1));
        }
      }
    }

    while (!stk.isEmpty()) {
      int top = stk.removeLast();
      if (stk.isEmpty()) {
        maxArea = Math.max(maxArea, (long) h[top] * i);
      } else {
        maxArea = Math.max(maxArea, (long) h[top] * (i - stk.getLast() - 1));
      }
    }

    return maxArea;
  }
}
