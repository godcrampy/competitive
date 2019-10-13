#include <iostream>

// pisano period of 10
const int pisano_period = 60;
// sum of pisano sequence of 10
const int sum_of_sequence = 280;

int last_digit_of_sum(long long number)
{
  if (number < 1)
    return 0;
  int sequence[pisano_period];
  sequence[0] = 0;
  sequence[1] = 1;
  for (int i = 2; i < pisano_period; ++i)
    sequence[i] = (sequence[i - 1] + sequence[i - 2]) % 10;

  int last_digit = 0;
  for (auto i = 0; i != number % pisano_period; ++i)
    last_digit += sequence[i + 1];
  return last_digit % 10;
}

int main(int argc, char const *argv[])
{
  long long a, b;
  std::cin >> a >> b;
  std::cout << (last_digit_of_sum(b) + 10 - last_digit_of_sum(a - 1)) % 10 << std::endl;
  return 0;
}
