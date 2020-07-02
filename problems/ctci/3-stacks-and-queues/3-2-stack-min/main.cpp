#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// * IMP

class MinStack {
 private:
  vector<pair<int, int>> v;  // first => number stored, second => min till now
  int top = -1;

 public:
  MinStack(int size) { v = vector<pair<int, int>>(size); }

  void push(int a) {
    if (top == -1) {
      v[++top] = {a, a};
      return;
    }

    if (top < v.size() - 1) {
      v[top + 1] = {a, min(a, v[top].second)};
      ++top;
    }
  }

  int pop() {
    if (top >= 0) return v[top--].first;
    return -1;
  }

  int getMin() { return v[top].second; }

  int getTop() { return v[top].first; }
};

int main(int argc, char const *argv[]) {
  MinStack s(10);

  s.push(8);
  s.push(7);
  s.push(18);
  s.push(1);

  cout << s.getMin() << endl;
  cout << s.getTop() << endl;

  s.pop();

  cout << s.getMin() << endl;
  cout << s.getTop() << endl;
  return 0;
}
