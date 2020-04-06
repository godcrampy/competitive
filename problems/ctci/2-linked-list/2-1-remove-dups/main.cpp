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

void removeDupsSet(ListNode* head) {
  // * Time: O(n)
  // * Space: O(n)
  unordered_set<int> s;
  ListNode* d = new ListNode(0);
  d->next = head;
  while (d->next != NULL) {
    if (s.find(d->next->val) != s.end()) {
      // delete next
      d->next = d->next->next;
    } else {
      d = d->next;
      s.insert(d->val);
    }
  }
}

void removeDupWithoutBuffer(ListNode* head) {
  // * Time: O(n^2)
  // * Space: O(1)
  ListNode* s = head;
  ListNode* f = head;
  while (s != NULL) {
    f = s;
    while (f->next != NULL) {
      if (f->next->val == s->val) {
        f->next = f->next->next;
      } else {
        f = f->next;
      }
    }
    s = s->next;
  }
}

int main(int argc, char const* argv[]) {
  vector<int> v = {5, 7, 1, 3, 9, 7, 7, 5, 0};
  auto head = arrayToList(v);
  printList(head);
  removeDupWithoutBuffer(head);
  printList(head);
  return 0;
}
