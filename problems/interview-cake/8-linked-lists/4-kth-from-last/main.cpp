#include <iostream>
#include <vector>

using namespace std;

class LinkedListNode {
 public:
  int intValue_;
  LinkedListNode* next_;

  LinkedListNode(int value) : intValue_(value), next_(nullptr) {}
};

int getLength(LinkedListNode* head) {
  int count = 0;
  while (head != nullptr) {
    ++count;
    head = head->next_;
  }
  return count;
}

LinkedListNode* kthToLastNode(size_t k, LinkedListNode* head) {
  // return the kth to last node in the linked list
  int n = getLength(head);
  if (k > n || k <= 0) {
    throw "";
  }

  for (int i = 0; i < n - k; ++i) {
    head = head->next_;
  }

  return head;
}
