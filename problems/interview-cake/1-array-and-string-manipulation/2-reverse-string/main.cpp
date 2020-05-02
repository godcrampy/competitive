#include <iostream>
#include <string>

using namespace std;

void reverse(string& str) {
  // reverse the input string in place
  int l = 0;
  int r = str.length() - 1;
  while (l < r) {
    swap(str[l], str[r]);
    ++l;
    --r;
  }
}
