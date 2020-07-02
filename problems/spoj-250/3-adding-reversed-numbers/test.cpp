#include <iostream>

#include "util.h"

using namespace std;

int main(int argc, char const *argv[]) {
  printf("%d\n", reverseNumber(atoi(*(argv + 1))));
  return 0;
}
