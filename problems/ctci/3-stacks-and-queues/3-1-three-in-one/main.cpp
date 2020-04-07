#include <iostream>
#include <vector>

using namespace std;

// * Book presents 2 solutions, first is allocating one third space to each stack
// * Second is to use dynamic space which is out of the scope of the interview
// * Here's a 2 stack implementation

template <typename T>
class BiStack {
 private:
  vector<T> v;
  int l;  // pointer to left stack top
  int r;  // pointer to right stack top

 public:
  BiStack(int size) {
    this->v = vector<T>(2 * size, 0);
    this->l = 0;
    this->r = v.size() - 1;
  }

  T topLeft() {
    return this->v[this->l];
  }

  T topRight() {
    return this->v[this->r];
  }

  void pushLeft(T a) {
    if (l < r - 1) {
      this->v[++l] = a;
    }
  }

  void pushRight(T a) {
    if (l < r - 1) {
      this->v[--r] = a;
    }
  }

  void popLeft() {
    --l;
  }

  void popRight() {
    ++r;
  }

  int sizeLeft() {
    return l;
  }

  int sizeRight() {
    return v.size() - r;
  }
};

int main(int argc, char const *argv[]) {
  BiStack<int> a(10);
  a.pushLeft(1);
  a.pushLeft(2);
  a.pushRight(9);
  a.pushRight(8);
  cout << a.sizeLeft() << endl;
  cout << a.topLeft() << endl;
  cout << a.sizeRight() << endl;
  cout << a.topRight() << endl;
  a.popRight();
  cout << a.topRight() << endl;
}
