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

// ! IMP

ListNode* getLoopStart(ListNode* head) {
  if (head == NULL) return NULL;
  ListNode* slow = head;
  ListNode* fast = head->next;

  while (fast != NULL && fast->next != NULL && slow != fast) {
    slow = slow->next;
    fast = fast->next->next;
  }

  if (slow != fast) {
    // fast at end of node
    return NULL;
  }

  slow = slow->next;

  ListNode* a = head;
  while (a != slow) {
    a = a->next;
    slow = slow->next;
  }

  return a;
}

int main(int argc, char const* argv[]) {
  vector<int> v = {1, 2, 3, 4, 5};
  auto head = arrayToList(v);
  head->next->next->next->next->next = head->next->next;  // five and three connected
  cout << getLoopStart(head)->val << endl;
  return 0;
}
