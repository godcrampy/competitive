#include <iostream>

int number_of_times(long a, long b)
{
  if (b <= ((a - 1) / 2))
    return 1;
  return -1;
}

int main()
{
  int t;
  std::cin >> t;
  long a, b;
  for (int _ = 0; _ < t; _++)
  {
    std::cin >> a >> b;
    std::cout << number_of_times(a, b) << std::endl;
  }
  return 0;
}
