class Solution {
  // Function to find the nth node from end in the linked list
  // head: head of the linked list
  // n: nth node from end to find
  int length(Node head) {
    int n = 0;
    while (head != null) {
      head = head.next;
      ++n;
    }
    return n;
  }
  int getNthFromLast(Node head, int n) {
    // Your code here
    int k = length(head) - n;
    if (k < 0) {
      return -1;
    }
    while (k-- != 0) {
      head = head.next;
    }
    return head.data;
  }
}
