#include <iostream>

using namespace std;

// ! IMP

int next_number(int n) {
  int temp = n;
  int c0 = 0;
  int c1 = 0;
  while (((temp & 1) == 0) && temp != 0) {
    ++c0;
    temp >>= 1;
  }
  while ((temp & 1) == 1) {
    ++c1;
    temp >>= 1;
  }

  int p = c0 + c1;
  if (p == 31 || p == 0) {
    return -1;
  }

  n |= (1 << p);
  n &= ~((1 << p) - 1);

  n |= (1 << (c1 - 1)) - 1;
  return n;
}

int prev_number(int n) {
  int temp = n;
  int c0 = 0;
  int c1 = 0;
  while ((temp & 1) == 1) {
    ++c1;
    temp >>= 1;
  }
  if (temp == 0) return -1;

  while (((temp & 1) == 0) && temp != 0) {
    ++c0;
    temp >>= 1;
  }

  int p = c0 + c1;

  n &= ((~0) << (p + 1));

  int mask = (1 << (c1 + 1)) - 1;

  n |= mask << (c0 - 1);

  return n;
}

int main(int argc, char const *argv[]) {
  cout << next_number(6) << endl;
  cout << prev_number(9) << endl;
  return 0;
}
