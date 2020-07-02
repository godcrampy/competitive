#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class LinkedListNode {
 public:
  int intValue_;
  LinkedListNode* next_;

  LinkedListNode(int value) : intValue_(value), next_(nullptr) {}
};

void deleteNode(LinkedListNode* nodeToDelete) {
  // delete the input node from the linked list
  if (nodeToDelete == nullptr || nodeToDelete->next_ == nullptr) {
    throw "";
  }

  nodeToDelete->intValue_ = nodeToDelete->next_->intValue_;

  while (nodeToDelete->next_->next_ != nullptr) {
    nodeToDelete->next_->intValue_ = nodeToDelete->next_->next_->intValue_;
    nodeToDelete = nodeToDelete->next_;
  }

  nodeToDelete->intValue_ = nodeToDelete->next_->intValue_;
  nodeToDelete->next_ = nullptr;
}
