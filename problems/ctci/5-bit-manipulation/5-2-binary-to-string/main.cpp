#include <iostream>
#include <string>

using namespace std;

string binary_to_string(double n) {
  // * Time: O(1)
  // * Space: O(1)
  string res = "0.";
  for (int i = 1; i <= 32; ++i) {
    double div = (double)1 / (1 << i);
    if (n >= div) {
      n -= div;
      res += "1";
      if (n == 0) break;
    } else {
      res += "0";
    }
  }

  if (n != 0) {
    return "ERROR";
  }
  return res;
}

int main(int argc, char const *argv[]) {
  double n = 0.273;
  cout << binary_to_string(n) << endl;
  return 0;
}
