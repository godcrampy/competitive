// Sahil Code
// Both algorithms seem same but for some reason this one is WA

#include <iostream>

int get_power_LSB(int base, int index)
{
  int final = 1;
  for (int i = 0; i < index; i++)
    final *= base;
  return final % 10;
}

int get_last_digit(int base, int index)
{
  int c = index % 4;
  base %= 10;
  return get_power_LSB(base, c);
}

int main(int argc, char const *argv[])
{
  int t, a;
  int b;
  std::cin >> t;

  for (int _ = 0; _ < t; _++)
  {
    std::cin >> a >> b;
    std::cout << get_last_digit(a, b) << std::endl;
  }
  return 0;
}
