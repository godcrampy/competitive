#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class SetOfStack {
 private:
  vector<stack<int>> v;
  int stackCapacity;

 public:
  SetOfStack(int capacity) : stackCapacity(capacity) {}

  void push(int n) {
    if ((v.size() == 0) || (v.end() - 1)->size() == stackCapacity) {
      stack<int> a;
      a.push(n);
      v.push_back(a);
    } else {
      (v.end() - 1)->push(n);
    }
  }

  int pop(int n) {
    int res = (v.end() - 1)->top();
    (v.end() - 1)->pop();
    if ((v.end() - 1)->size() == 0) v.pop_back();
    return res;
  }

  int top() { return (v.end() - 1)->top(); }
};

int main(int argc, char const *argv[]) {
  SetOfStack a(2);
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);

  cout << a.top() << endl;
  return 0;
}
