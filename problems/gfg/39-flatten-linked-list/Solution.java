class Solution {
  Node merge(Node a, Node b) {
    Node d = new Node(0);
    Node i = d;

    while (a != null || b != null) {
      int l = a == null ? Integer.MAX_VALUE : a.data;
      int r = b == null ? Integer.MAX_VALUE : b.data;
      if (l < r) {
        i.bottom = a;
        a = a.bottom;
      } else {
        i.bottom = b;
        b = b.bottom;
      }
      i = i.bottom;
    }

    return d.bottom;
  }

  Node flatten(Node root) {
    if (root == null || root.next == null) {
      return root;
    }

    root.next = flatten(root.next);

    root = merge(root, root.next);

    return root;
  }
}
