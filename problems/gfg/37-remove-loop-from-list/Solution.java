
/*
class Node
{
    int data;
    Node next;
}
*/

class Solution {
  public static void removeLoop(Node head) {
    if (head == null || head.next == null) {
      return;
    }

    Node s = head.next;
    Node f = head.next.next;

    while (f != null && f.next != null && s != f) {
      s = s.next;
      f = f.next.next;
    }

    if (f == null || f.next == null) {
      return;
    }

    s = head;
    while (s != f) {
      f = f.next;
      s = s.next;
    }

    while (s.next != f) {
      s = s.next;
    }

    s.next = null;
  }
}