#include <cstddef>  // NULL definition

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* l3 = new ListNode(0);
  ListNode* head = l3;

  int carry = 0;
  while (l1 != NULL || l2 != NULL) {
    int l1_val = (l1 == NULL) ? 0 : l1->val;
    int l2_val = (l2 == NULL) ? 0 : l2->val;

    int sum = l1_val + l2_val + carry;

    l3->next = new ListNode(sum % 10);
    carry = sum / 10;
    l3 = l3->next;

    if (l1 != NULL) l1 = l1->next;
    if (l2 != NULL) l2 = l2->next;
  }

  if (carry) {
    l3->next = new ListNode(1);
  }

  return head->next;
}