#include <cmath>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNode(ListNode* head) {
  ListNode* s = head;
  ListNode* f = head->next;

  while (f != NULL && f->next != NULL) {
    s = s->next;
    f = f->next->next;
  }

  if (f == NULL) {
    return s;
  }
  return s->next;
}