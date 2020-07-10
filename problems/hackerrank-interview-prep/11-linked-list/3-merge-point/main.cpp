#include <bits/stdc++.h>

using namespace std;

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
  int l1 = 0;
  int l2 = 0;
  SinglyLinkedListNode* h1 = head1;
  SinglyLinkedListNode* h2 = head2;

  while (head1 != NULL) {
    head1 = head1->next;
    ++l1;
  }

  while (head2 != NULL) {
    head2 = head2->next;
    ++l2;
  }

  int diff = abs(l1 - l2);

  if (l1 > l2) {
    while (diff--) {
      h1 = h1->next;
    }
  } else {
    while (diff--) {
      h2 = h2->next;
    }
  }

  while (h1 != h2) {
    h1 = h1->next;
    h2 = h2->next;
  }

  return h1->data;
}
