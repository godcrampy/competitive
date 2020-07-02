// Aemie Code

#include <iostream>
using namespace std;
int power_calculation(int base, int exponent) {
  int result = 1;
  for (int _ = 0; _ < exponent; _++) result *= base;
  return result;
}
int main() {
  int test, base, power;
  cin >> test;
  for (int _ = 0; _ < test; _++) {
    cin >> base >> power;
    if (power < 4)
      cout << power_calculation(base, power) % 10 << endl;
    else
      for (int i = 1; i <= 4; i++)
        if (((power - i) % 4) == 0) {
          cout << power_calculation(base, i) % 10 << endl;
          break;
        }
  }
  return 0;
}