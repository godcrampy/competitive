#include <iostream>

#include "util.h"

using namespace std;

int main(int argc, char** argv) {
  cout << isPrime(atoi(*(argv + 1))) << endl;
  ;
  return 0;
}
