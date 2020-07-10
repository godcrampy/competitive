class Solution {
  /*
class Node
  int data;
  Node left;
  Node right;
  */
  public static Node lca(Node root, int v1, int v2) {
    if (root == null) {
      return null;
    }

    if (root.data == v1 || root.data == v2) {
      return root;
    }

    Node left = lca(root.left, v1, v2);
    Node right = lca(root.right, v1, v2);

    if (left != null && right != null) {
      return root;
    }

    return left != null ? left : right;
  }
}
