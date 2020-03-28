#include <cstdlib>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode* d3 = new ListNode(0);
  ListNode* itr = d3;

  while (l1 != NULL && l2 != NULL) {
    if (l1->val < l2->val) {
      itr->next = l1;
      l1 = l1->next;
    } else {
      itr->next = l2;
      l2 = l2->next;
    }
    itr = itr->next;
  }

  if (l1 != NULL) {
    itr->next = l1;
  }

  if (l2 != NULL) {
    itr->next = l2;
  }

  return d3->next;
}