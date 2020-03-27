const int NULL = 0;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

int length(ListNode* head) {
  int n = 0;
  while (head != NULL) {
    head = head->next;
    ++n;
  }
  return n;
}

ListNode* removeNthFromEndTwoPass(ListNode* head, int n) {
  int l = length(head);
  int t = l - n - 1;
  if (l == n) {
    return head->next;
  }
  int i = 0;
  auto itr = head;

  while (i != t) {
    itr = itr->next;
    ++i;
  }

  itr->next = itr->next->next;

  return head;
}

ListNode* removeNthFromEndSinglePass(ListNode* head, int n) {
  auto d = new ListNode(0);
  d->next = head;
  auto s = d;
  auto f = d;

  for (int i = 0; i < n; ++i) {
    f = f->next;
  }

  while (f->next != NULL) {
    s = s->next;
    f = f->next;
  }

  s->next = s->next->next;

  return d->next;
}