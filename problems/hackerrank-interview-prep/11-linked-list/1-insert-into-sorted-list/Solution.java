public class Solution {
  // Complete the sortedInsert function below.

  /*
   * For your reference:
   *
   * DoublyLinkedListNode {
   *     int data;
   *     DoublyLinkedListNode next;
   *     DoublyLinkedListNode prev;
   * }
   *
   */
  static DoublyLinkedListNode sortedInsert(DoublyLinkedListNode head, int data) {
    DoublyLinkedListNode d = new DoublyLinkedListNode(Integer.MIN_VALUE);
    DoublyLinkedListNode n = new DoublyLinkedListNode(data);
    d.next = head;
    head.prev = d;
    DoublyLinkedListNode i = d;

    while (i.next != null && i.next.data < data) {
      i = i.next;
    }

    n.next = i.next;
    if (i.next != null) {
      i.next.prev = n;
    }
    i.next = n;
    n.prev = i;

    return d.next;
  }
}
