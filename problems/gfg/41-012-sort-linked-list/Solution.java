class Solution {
  static Node segregate(Node head) {
    // add your code here
    int z = 0, o = 0, t = 0;
    while (head != null) {
      if (head.data == 0) {
        ++z;
      } else if (head.data == 1) {
        ++o;
      } else {
        ++t;
      }
      head = head.next;
    }

    Node d = new Node(0);
    Node i = d;

    while (z-- != 0) {
      i.next = new Node(0);
      i = i.next;
    }

    while (o-- != 0) {
      i.next = new Node(1);
      i = i.next;
    }

    while (t-- != 0) {
      i.next = new Node(2);
      i = i.next;
    }

    return d.next;
  }
}
