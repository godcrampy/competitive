#include <iostream>

#include "util.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int number{};
  while (true) {
    cin >> number;
    if (number == 0) break;
    cout << totalPositions(number) << endl;
  }
  return 0;
}
