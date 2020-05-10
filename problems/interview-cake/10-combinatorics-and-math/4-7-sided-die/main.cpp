#include <iostream>
#include <random>

using namespace std;

// ! IMP

int rand5() {
  static random_device rd;
  static mt19937 g(rd());
  static uniform_int_distribution<int> d(1, 5);
  return d(g);
}

int rand7() {
  // implement rand7() using rand5()
  while (true) {
    int i1 = rand5() - 1;
    int i2 = rand5() - 1;

    int n = i1 * 5 + i2;

    if (n > 21) {
      continue;
    }

    return n % 7 + 1;
  }

  return 0;
}
