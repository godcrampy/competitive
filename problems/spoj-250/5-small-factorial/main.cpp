#include <iostream>

using namespace std;
#include "util.h"

int main(int argc, char const *argv[])
{
  const int MAXIMUM_ARRAY_SIZE = 500;
  int t;
  cin >> t;
  for (int _ = 0; _ < t; _++)
  {
    int bigInt[MAXIMUM_ARRAY_SIZE] = {1};
    int length = 1;
    int number{};
    cin >> number;
    factorial(bigInt, length, number);
    printBigInt(bigInt, length);
  }
  return 0;
}
