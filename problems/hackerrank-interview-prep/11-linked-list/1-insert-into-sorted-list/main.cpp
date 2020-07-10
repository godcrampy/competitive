#include <bits/stdc++.h>

using namespace std;

// Complete the sortedInsert function below.

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
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
  DoublyLinkedListNode* d = new DoublyLinkedListNode(INT_MIN);
  d->next = head;
  head->prev = d;
  DoublyLinkedListNode* n = new DoublyLinkedListNode(data);
  DoublyLinkedListNode* i = d;

  while (i->next != nullptr && i->next->data < data) {
    i = i->next;
  }

  n->next = i->next;
  if (i->next != nullptr) {
    i->next->prev = n;
  }
  i->next = n;
  n->prev = i;

  return d->next;
}
