#include <iostream>

using namespace std;

int numberOfTrailingZerosInFactorial(int number) {
  int zeroes = 0;
  while (number != 0) {
    zeroes += number / 5;
    number /= 5;
  }
  return zeroes;
}

int main() {
  int t, number;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> number;
    cout << numberOfTrailingZerosInFactorial(number) << endl;
  }
  return 0;
}
