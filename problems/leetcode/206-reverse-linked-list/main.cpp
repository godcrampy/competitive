#include <cmath>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode* d = new ListNode(0);
  d->next = head;

  ListNode* a = d;
  ListNode* b = head;
  ListNode* c = head->next;

  while (c != NULL) {
    b->next = a;
    a = b;
    b = c;
    c = c->next;
  }

  d->next->next = NULL;
  b->next = a;
  return b;
}