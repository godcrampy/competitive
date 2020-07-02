#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
 private:
  stack<int> l;
  stack<int> r;

 public:
  void add(int n) { l.push(n); }

  int remove() {
    while (l.size() > 1) {
      r.push(l.top());
      l.pop();
    }
    int res = l.top();
    l.pop();
    while (!r.empty()) {
      l.push(r.top());
      r.pop();
    }

    return res;
  }

  int peek() {
    while (l.size() > 1) {
      r.push(l.top());
      l.pop();
    }
    int res = l.top();
    while (!r.empty()) {
      l.push(r.top());
      r.pop();
    }

    return res;
  }

  bool empty() { return l.empty(); }
};

int main(int argc, char const *argv[]) {
  MyQueue a;
  a.add(1);
  a.add(2);
  a.add(3);

  cout << a.remove() << endl;
  cout << a.remove() << endl;
  cout << a.peek() << endl;

  return 0;
}
