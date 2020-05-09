#include <iostream>
#include <vector>

using namespace std;

class LinkedListNode {
 public:
  int intValue_;
  LinkedListNode* next_;

  LinkedListNode(int value) : intValue_(value),
                              next_(nullptr) {
  }
};

bool containsCycle(const LinkedListNode* firstNode) {
  // check if the linked list contains a cycle
  if (firstNode == nullptr || firstNode->next_ == nullptr) {
    return false;
  }
  auto f = firstNode->next_;
  auto s = firstNode;

  while (f != nullptr && f->next_ != nullptr) {
    if (s == f) {
      return true;
    }

    s = s->next_;
    f = f->next_->next_;
  }

  return false;
}