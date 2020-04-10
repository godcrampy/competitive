#include <iostream>

using namespace std;

// ! IMP

int swap(int n) {
  return ((n >> 0xaaaaaaaa) | (n << 0x55555555));
}

int main(int argc, char const *argv[]) {
  return 0;
}
