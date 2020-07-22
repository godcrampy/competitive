class Solution {
  static int length(Node root) {
    int n = 0;
    while (root != null) {
      root = root.next;
      ++n;
    }

    return n;
  }

  static Node makeZeroList(Node root, int n) {
    Node i = root;
    while (n-- != 0) {
      i.next = new Node(0);
      i = i.next;
    }
    return i;
  }

  static int addRecursively(Node first, Node second) {
    if (first == null || second == null) {
      return 0;
    }

    int carry = addRecursively(first.next, second.next);
    int sum = carry + first.data + second.data;
    first.data = sum % 10;
    return sum / 10;
  }

  static Node addLists(Node first, Node second) {
    // code here
    // return head of sum list
    int l1 = length(first);
    int l2 = length(second);

    if (l1 > l2) {
      int diff = l1 - l2;
      Node d = new Node(0);
      Node last = makeZeroList(d, diff - 1);
      last.next = second;
      second = d;
    }

    if (l2 > l1) {
      int diff = l2 - l1;
      Node d = new Node(0);
      Node last = makeZeroList(d, diff - 1);
      last.next = first;
      first = d;
    }

    int carry = addRecursively(first, second);
    if (carry != 0) {
      Node d = new Node(1);
      d.next = first;
      return d;
    }

    return first;
  }
}
