#include <iostream>

#include "util.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int t, l, r;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    cin >> l >> r;
    cout << reverseNumber(reverseNumber(l) + reverseNumber(r)) << endl;
  }
  return 0;
}
