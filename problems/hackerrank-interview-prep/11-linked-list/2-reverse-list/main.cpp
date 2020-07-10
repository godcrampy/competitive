#include <bits/stdc++.h>

using namespace std;
// Complete the reverse function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
  while (head->next != NULL) {
    swap(head->next, head->prev);
    head = head->prev;
  }
  head->next = head->prev;
  head->prev = NULL;

  return head;
}
