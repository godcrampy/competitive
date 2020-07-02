#include <cmath>
#include <stack>

using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
  if (head == NULL) {
    return true;
  }
  ListNode* f = head->next;
  ListNode* s = head;
  stack<int> stk;

  while (f != NULL && f->next != NULL) {
    stk.push(s->val);
    s = s->next;
    f = f->next->next;
  }

  if (f != NULL) {
    stk.push(s->val);
  }
  s = s->next;

  while (s != NULL && !stk.empty()) {
    if (s->val != stk.top()) {
      return false;
    }
    s = s->next;
    stk.pop();
  }

  if (s == NULL && stk.empty()) return true;
  return false;
}