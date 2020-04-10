#include <iostream>

using namespace std;

int diff(int a, int b) {
  int n = a ^ b;
  int count = 0;
  while (n != 0) {
    if (n & 1) {
      ++count;
    }
    n >>= 1;
  }
  return count;
}

int main(int argc, char const *argv[]) {
  cout << diff(1, 5) << endl;
  return 0;
}
