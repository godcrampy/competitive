#include <iostream>
#include <limits>

using namespace std;

// ! IMP

int longest_sequence_after_flip(int n) {
  if (~n == 0) return numeric_limits<int>::digits;

  int current = 0;
  int previous = 0;
  int max_length = 0;

  while (n != 0) {
    if (n & 1) {
      // bit is one
      ++current;
    } else {
      // bit is zero
      if (n & 2) {
        // next bit is zero as well
        previous = current;
      } else {
        // next bit is one
        previous = 0;
      }
      current = 0;
    }

    max_length = max(current + previous + 1, max_length);
    n = n >> 1;
  }
  return max_length;
}

int main(int argc, char const *argv[]) {
  cout << longest_sequence_after_flip(1775) << endl;
  return 0;
}
