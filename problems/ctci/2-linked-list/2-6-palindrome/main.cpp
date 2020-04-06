#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

// ? Singly Linked List Boiler
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* arrayToList(const vector<int>& v) {
  if (v.size() == 0) return NULL;
  ListNode* dummy = new ListNode(0);
  ListNode* itr = dummy;
  for (int n : v) {
    itr->next = new ListNode(n);
    itr = itr->next;
  }
  return dummy->next;
}

void printList(ListNode* head) {
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
// ? End of Single Linked List Boiler

ListNode* copyList(ListNode* a) {
  ListNode* d = new ListNode(0);
  ListNode* res = d;
  while (a != NULL) {
    d->next = new ListNode(a->val);
    a = a->next;
    d = d->next;
  }
  return res->next;
}

ListNode* reverseList(ListNode* head) {
  if (head == NULL || head->next == NULL) return head;
  ListNode* a = head;
  ListNode* b = head->next;
  ListNode* c = b->next;
  head->next = NULL;
  while (c != NULL) {
    b->next = a;
    a = b;
    b = c;
    c = c->next;
  }
  b->next = a;
  return b;
}

bool isPalindromeRev(ListNode* a) {
  auto b = reverseList(copyList(a));
  while (a != NULL || b != NULL) {
    if (a == NULL || b == NULL) {
      return false;
    }
    if (a->val != b->val) {
      return false;
    }
    a = a->next;
    b = b->next;
  }
  return true;
}

bool isPalindromeStack(ListNode* a) {
  if (a == NULL || a->next == NULL) {
    return true;
  }
  stack<int> stk;
  ListNode* s = a;
  ListNode* f = a->next;
  while (f != NULL && f->next != NULL) {
    stk.push(s->val);
    s = s->next;
    f = f->next->next;
  }

  if (f == NULL)
    s = s->next;
  else {
    stk.push(s->val);
    s = s->next;
  }

  while (!stk.empty() && s != NULL) {
    int t = stk.top();
    stk.pop();
    if (t != s->val) return false;
    s = s->next;
  }

  return stk.empty() && s == NULL;
}

int main(int argc, char const* argv[]) {
  vector<int> v = {1, 2, 6, 5, 2, 1};
  auto a = arrayToList(v);
  cout << isPalindromeStack(a) << endl;

  return 0;
}
