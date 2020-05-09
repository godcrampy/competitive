#include <iostream>
#include <stack>

using namespace std;

// ! IMP Dynamic Array like approach

// fill in the definitions for enqueue() and dequeue()

class QueueTwoStacks {
 private:
  stack<int> inStack_;
  stack<int> outStack_;

 public:
  void enqueue(int item) {
    inStack_.push(item);
  }

  int dequeue() {
    if (outStack_.empty()) {
      // fill everything from instack
      while (!inStack_.empty()) {
        int temp = inStack_.top();
        inStack_.pop();
        outStack_.push(temp);
      }

      if (outStack_.empty()) {
        throw "";
      }
    }

    int res = outStack_.top();
    outStack_.pop();
    return res;
  }
};
