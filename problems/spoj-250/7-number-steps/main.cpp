#include <iostream>
#include "util.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int t, x, y;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    cin >> x >> y;
    if (isValid(x, y))
      cout << getNumber(x, y) << endl;
    else
      cout << "No Number" << endl;
  }
  return 0;
}
