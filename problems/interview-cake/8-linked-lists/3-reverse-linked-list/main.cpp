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

LinkedListNode* reverse(LinkedListNode* headOfList) {
  // reverse the linked list in place
  if (headOfList == nullptr || headOfList->next_ == nullptr) {
    return headOfList;
  }

  auto a = headOfList;
  auto b = a->next_;
  auto c = b->next_;
  a->next_ = nullptr;

  while (true) {
    b->next_ = a;

    a = b;
    b = c;
    if (c == nullptr) {
      break;
    }
    c = c->next_;
  }

  return a;
}
