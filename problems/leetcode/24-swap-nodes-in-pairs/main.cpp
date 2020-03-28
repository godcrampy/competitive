#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
  if (head == NULL || head->next == NULL)
    return head;

  ListNode* d = new ListNode(0);
  d->next = head;
  ListNode* a = d;
  ListNode* b = d->next;

  while (b != NULL && b->next != NULL) {
    a->next = b->next;
    b->next = a->next->next;
    a->next->next = b;
    a = a->next->next;
    b = b->next;
  }

  return d->next;
}