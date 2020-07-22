struct node* reverseAll(struct node* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  struct node* a = head;
  struct node* b = head->next;
  struct node* c = head->next->next;
  a->next = NULL;

  while (true) {
    b->next = a;
    a = b;
    b = c;
    if (c == NULL) {
      break;
    }
    c = c->next;
  }

  return a;
}

struct node* reverse(struct node* head, int k) {
  // Complete this method
  if (head == NULL || head->next == NULL) {
    return head;
  }
  struct node* dummy = new node(0);
  dummy->next = head;
  struct node* a = dummy;
  struct node* b = NULL;
  struct node* c = NULL;
  struct node* d = NULL;
  while (a != NULL && a->next != NULL) {
    b = a;
    int i = k;
    while (i-- && b->next != NULL) {
      b = b->next;
    }
    c = b->next;
    d = a->next;
    b->next = NULL;
    a->next = reverseAll(a->next);
    d->next = c;
    a = d;
  }

  return dummy->next;
}
