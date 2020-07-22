import java.util.*;

public class Solution {
  static class Node implements Comparable<Node> {
    public int index;
    public int val;

    Node(int index, int val) {
      this.index = index;
      this.val = val;
    }

    public int compareTo(Node b) {
      return val - b.val;
    }
  }

  static void constructTree(int[] v, Node[] sT, int l, int r, int pos) {
    if (l == r) {
      sT[pos] = new Node(l, v[l]);
      return;
    }

    int m = l + (r - l) / 2;
    constructTree(v, sT, l, m, 2 * pos + 1);
    constructTree(v, sT, m + 1, r, 2 * pos + 2);
    Node a = sT[2 * pos + 1];
    Node b = sT[2 * pos + 2];
    if (a.val < b.val) {
      sT[pos] = a;
    } else {
      sT[pos] = b;
    }
  }

  static Node rangeMinQuery(Node[] sT, int l, int r, int ql, int qr, int pos) {
    if (ql <= l && qr >= r) {
      return sT[pos];
    }

    if (ql > r || qr < l) {
      return new Node(-1, Integer.MAX_VALUE);
    }

    int m = l + (r - l) / 2;
    Node a = rangeMinQuery(sT, l, m, ql, qr, 2 * pos + 1);
    Node b = rangeMinQuery(sT, m + 1, r, ql, qr, 2 * pos + 2);
    return a.val < b.val ? a : b;
  }

  static long largestRectangleRec(Node[] sT, int l, int r, int vsize) {
    if (l >= r) {
      return 0;
    }

    Node n = rangeMinQuery(sT, 0, vsize, l, r, 0);
    int minVal = n.val;
    int minIndex = n.index;
    return Math.max((r - l + 1) * minVal,
        Math.max(largestRectangleRec(sT, l, minIndex - 1, vsize),
            largestRectangleRec(sT, minIndex + 1, r, vsize)));
  }

  // Complete the largestRectangle function below.
  static long largestRectangle(int[] h) {
    int n = h.length;
    Node[] sT = new Node[4 * n];
    constructTree(h, sT, 0, n - 1, 0);
    return largestRectangleRec(sT, 0, n - 1, n - 1);
  }
}
