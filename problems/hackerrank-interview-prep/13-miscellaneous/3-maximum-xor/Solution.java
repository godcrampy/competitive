public class Solution {
  static class Node {
    public int val;
    public Node[] children;

    Node() {
      val = 0;
      children = new Node[] {null, null};
    }

    Node(int val) {
      this.val = val;
      children = new Node[] {null, null};
    }
  }

  static void insert(Node trie, int n, int index) {
    if (index < 0) {
      return;
    }

    int x = (n >> index) & 1;

    if (trie.children[x] == null) {
      trie.children[x] = new Node(x);
    }

    insert(trie.children[x], n, index - 1);
  }

  static int getMax(Node trie, int n, int index, int p) {
    if (index < 0) {
      return p;
    }

    int x = (n >> index) & 1;
    x ^= 1;

    if (trie.children[x] != null) {
      p |= (x << index);
      return getMax(trie.children[x], n, index - 1, p);
    }

    x ^= 1;
    p |= (x << index);
    return getMax(trie.children[x], n, index - 1, p);
  }

  // Complete the maxXor function below.
  static int[] maxXor(int[] arr, int[] queries) {
    // solve here
    Node trie = new Node();

    for (int n : arr) {
      insert(trie, n, 31);
    }

    int[] res = new int[queries.length];

    for (int i = 0; i < queries.length; ++i) {
      int p = 0;
      p = getMax(trie, queries[i], 31, p);
      res[i] = queries[i] ^ p;
    }

    return res;
  }
}
