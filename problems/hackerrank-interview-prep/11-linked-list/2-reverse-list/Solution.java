public class Solution {
  // Complete the reverse function below.

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
  static DoublyLinkedListNode reverse(DoublyLinkedListNode head) {
    DoublyLinkedListNode temp = head;
    while (head.next != null) {
      temp = head.prev;
      head.prev = head.next;
      head.next = temp;
      head = head.prev;
    }

    head.next = head.prev;
    head.prev = null;

    return head;
  }
}
