#include <limits.h>

#include <iostream>
#include <stack>

using namespace std;

// ! IMP

// fill in the definitions for push(), pop(), and getMax()

class MaxStack {
 public:
  stack<int> stk;
  stack<int> maxStack;
  void push(int item) {
    stk.push(item);
    int maxTillNow = maxStack.empty() ? INT_MIN : maxStack.top();
    maxStack.push(max(maxTillNow, item));
  }

  int pop() {
    int res = stk.top();
    stk.pop();
    maxStack.pop();
    return res;
  }

  int getMax() const {
    return maxStack.top();
  }
};
