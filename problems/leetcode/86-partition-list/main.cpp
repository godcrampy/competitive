#include <cmath>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
  ListNode* smaller = new ListNode(0);
  ListNode* larger = new ListNode(0);
  ListNode* s = smaller;
  ListNode* l = larger;
  ListNode* i = head;

  while (i != NULL) {
    if (i->val < x) {
      // add to smaller
      s->next = i;
      s = s->next;
    } else {
      // add to bigger
      l->next = i;
      l = l->next;
    }
    i = i->next;
  }

  l->next = NULL;
  // join stuff
  s->next = larger->next;
  return smaller->next;
}