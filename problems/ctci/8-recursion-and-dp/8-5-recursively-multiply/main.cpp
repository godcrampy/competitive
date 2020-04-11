#include <iostream>

using namespace std;

int min_product(int smaller, int larger) {
  if (smaller == 0) return 0;
  if (smaller == 1) return larger;

  int s = smaller >> 1;
  int half = min_product(s, larger);

  if (smaller % 2 == 0) return half + half;
  return half + half + larger;
}

int product(int a, int b) {
  if (a < b) {
    return min_product(a, b);
  }
  return min_product(b, a);
}

int main(int argc, char const *argv[]) {
  int a, b;
  cin >> a >> b;
  cout << product(a, b) << endl;
  /* code */
  return 0;
}
