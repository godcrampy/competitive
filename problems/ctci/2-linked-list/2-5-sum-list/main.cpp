#include <iostream>
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

// ! IMP

ListNode* sumReverse(ListNode* a, ListNode* b) {
  // * Time: O(n)
  // * Space: O(1)
  ListNode* d = new ListNode(0);
  ListNode* res = d;
  if (a == NULL) {
    return b;
  }
  if (b == NULL) {
    return a;
  }
  int count = 0;
  while (a != NULL || b != NULL) {
    int a_val = a == NULL ? 0 : a->val;
    int b_val = b == NULL ? 0 : b->val;
    int sum = a_val + b_val + count;
    d->next = new ListNode(sum % 10);
    d = d->next;
    count = sum / 10;
    if (b != NULL) b = b->next;
    if (a != NULL) a = a->next;
  }

  if (count) {
    d->next = new ListNode(count);
  }
  return res->next;
}

int main(int argc, char const* argv[]) {
  vector<int> a = {7, 1, 6, 8};
  vector<int> b = {5, 9, 5};
  printList(sumReverse(arrayToList(a), arrayToList(b)));
  return 0;
}
