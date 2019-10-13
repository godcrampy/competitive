#include <iostream>

int last_digit_of_fibonacci(int number)
{
  int cache[number + 1];
  cache[0] = 0;
  cache[1] = 1;
  for (int i = 2; i <= number; ++i)
    cache[i] = (cache[i - 1] + cache[i - 2]) % 10;
  return cache[number];
}

int main(int argc, char const *argv[])
{
  int number;
  std::cin >> number;
  std::cout << last_digit_of_fibonacci(number) << std::endl;
  return 0;
}
