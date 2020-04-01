#include <cmath>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode* s = head;
  ListNode* f = head->next;

  while (f != NULL && f->next != NULL) {
    f = f->next->next;
    s = s->next;
  }

  ListNode* r = s->next;
  s->next = NULL;
  ListNode* l = sortList(head);
  r = sortList(r);

  return merge(l, r);
}

ListNode* merge(ListNode* l, ListNode* r) {
  ListNode* d = new ListNode(0);
  ListNode* i = d;

  while (l != NULL && r != NULL) {
    if (l->val < r->val) {
      i->next = l;
      l = l->next;
    } else {
      i->next = r;
      r = r->next;
    }
    i = i->next;
  }

  if (l != NULL) {
    i->next = l;
  }

  if (r != NULL) {
    i->next = r;
  }

  return d->next;
}