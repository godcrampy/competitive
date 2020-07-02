#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool are_next_k_not_null(ListNode* a, int k) {
  if (a == NULL) return false;
  for (int i = 0; i < k; ++i) {
    a = a->next;
    if (a == NULL) return false;
  }
  return true;
}

ListNode* get_kth_node(ListNode* a, int k) {
  for (int i = 0; i < k; ++i) {
    a = a->next;
  }
  return a;
}
ListNode* reverseKGroup(ListNode* head, int k) {
  if (k <= 1) {
    return head;
  }
  ListNode* dummy = new ListNode(0);
  dummy->next = head;

  ListNode* a = dummy;

  while (are_next_k_not_null(a, k)) {
    ListNode* b = a->next;
    ListNode* c = get_kth_node(a, k);
    ListNode* d = c->next;

    // reverse list
    ListNode* l1 = b;
    ListNode* l2 = l1->next;
    ListNode* l3 = l2->next;

    while (l1 != c) {
      l2->next = l1;
      l1 = l2;
      l2 = l3;
      if (l3 == NULL) break;
      l3 = l3->next;
    }

    a->next = c;
    b->next = d;
    a = b;
  }

  return dummy->next;
}