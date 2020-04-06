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

int getLength(ListNode* head) {
  int count = 0;
  while (head != NULL) {
    head = head->next;
    ++count;
  }
  return count;
}

ListNode* getIntersectionPoint(ListNode* a, ListNode* b) {
  // * Time: O(|a| + |b|)
  // * Space: O(1)
  int a_length = getLength(a);
  int b_length = getLength(b);
  if (a_length > b_length) {
    while (a_length != b_length) {
      --a_length;
      a = a->next;
    }
  }

  if (b_length > a_length) {
    while (a_length != b_length) {
      --b_length;
      b = b->next;
    }
  }

  while (a != b) {
    a = a->next;
    b = b->next;
  }
  return a;
}

int main(int argc, char const* argv[]) {
  vector<int> v = {1, 2, 3, 4, 5, 6};
  auto a = arrayToList(v);
  vector<int> v2 = {7, 8};
  auto b = arrayToList(v2);
  b->next->next = a->next->next->next;
  cout << getIntersectionPoint(a, b)->val << endl;
  return 0;
}
