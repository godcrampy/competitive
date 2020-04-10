#include <iostream>

using namespace std;

int get_set_i_to_j(int i, int j) {
  // returns a number with i to j bit set
  return (1 << (j + 1)) - (1 << (i));
}

int insert_m_in_n(int m, int n, int i, int j) {
  // * Time: O(1)
  // * Space: O(1)
  int mask = get_set_i_to_j(i, j);
  // mask m
  m = m << i;
  // mask n
  n &= ~mask;

  return m | n;
}

int main(int argc, char const *argv[]) {
  int m = 19;
  int n = 1024;
  int i = 2, j = 6;
  cout << insert_m_in_n(m, n, i, j) << endl;
  return 0;
}
