import java.math.*;

public class Solution {
  // Complete the findMergeNode function below.

  /*
   * For your reference:
   *
   * SinglyLinkedListNode {
   *     int data;
   *     SinglyLinkedListNode next;
   * }
   *
   */
  static int findMergeNode(SinglyLinkedListNode head1, SinglyLinkedListNode head2) {
    SinglyLinkedListNode h1 = head1;
    SinglyLinkedListNode h2 = head2;
    int l1 = 0, l2 = 0;

    while (h1 != null) {
      ++l1;
      h1 = h1.next;
    }

    while (h2 != null) {
      ++l2;
      h2 = h2.next;
    }

    int diff = Math.abs(l1 - l2);

    if (l1 > l2) {
      while (diff != 0) {
        head1 = head1.next;
        --diff;
      }
    } else {
      while (diff != 0) {
        head2 = head2.next;
        --diff;
      }
    }

    while (head1 != head2) {
      head1 = head1.next;
      head2 = head2.next;
    }

    return head1.data;
  }
}