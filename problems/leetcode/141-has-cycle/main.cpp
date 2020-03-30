#include <cmath>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
  if (head == NULL) return false;

  ListNode* s = head;
  ListNode* f = head->next;

  while (f != NULL && f->next != NULL) {
    if (f == s || f->next == s) {
      return true;
    }
    f = f->next->next;
    s = s->next;
  }

  return false;
}