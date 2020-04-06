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
ListNode* partition(ListNode* head, int val) {
  ListNode* l = new ListNode(0);
  ListNode* r = new ListNode(0);
  ListNode* r_head = r;
  ListNode* l_head = l;
  auto i = head;

  while (i != NULL) {
    if (i->val < val) {
      l->next = i;
      l = l->next;
    } else {
      r->next = i;
      r = r->next;
    }
    i = i->next;
  }
  r->next = NULL;
  l->next = r_head->next;
  return l_head->next;
}

int main(int argc, char const* argv[]) {
  vector<int> v = {3, 5, 8, 5, 10, 2, 1};
  auto head = arrayToList(v);
  printList(partition(head, 5));
  return 0;
}
