#include <iostream>
#include <stack>

using namespace std;

// ! IMP

stack<int> sortStack(stack<int> &s) {
  // * Time: O(n^2)
  // * Space: O(n)
  stack<int> sorted;
  int count = 0;  // count of number of elements from sorted stack in s
  while (!s.empty()) {
    int top = s.top();
    s.pop();
    while (!sorted.empty() && sorted.top() <= top) {
      ++count;
      s.push(sorted.top());
      sorted.pop();
    }
    sorted.push(top);
    while (count > 0) {
      --count;
      sorted.push(s.top());
      s.pop();
    }
  }
  return sorted;
}

int main(int argc, char const *argv[]) {
  stack<int> s;
  s.push(5);
  s.push(8);
  s.push(4);
  s.push(1);
  s.push(3);
  s.push(2);
  s.push(7);
  s.push(4);

  s = sortStack(s);
  cout << s.top() << endl;
  /* code */
  return 0;
}
