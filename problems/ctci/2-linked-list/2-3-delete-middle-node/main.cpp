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

void deleteNode(ListNode* node) {
  // * Time: O(n)
  // * Space: O(1)
  if (node == NULL && node->next == NULL) return;

  while (node->next != NULL && node->next->next != NULL) {
    node->val = node->next->val;
    node = node->next;
  }
  node->val = node->next->val;
  node->next = NULL;
}

int main(int argc, char const* argv[]) {
  vector<int> v = {5, 8, 3, 4, 4, 5};
  auto head = arrayToList(v);
  printList(head);
  deleteNode(head->next->next);
  printList(head);
  return 0;
}
