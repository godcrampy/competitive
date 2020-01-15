#include <iostream>

//https://math.stackexchange.com/questions/442459/for-the-fibonacci-numbers-show-for-all-n-f-12f-22-dotsf-n2-f-nf-n1

// pisano period of 10
const int pisano_period = 60;
// sum of pisano sequence of 10
const int sum_of_sequence = 280;

int last_digit_of_fibonacci(long long number) {
  int seq[pisano_period];
  seq[0] = 0;
  seq[1] = 1;
  for (auto i = 2; i < 60; ++i)
    seq[i] = (seq[i - 1] + seq[i - 2]) % 10;
  return seq[number % pisano_period];
}

int main(int argc, char const *argv[]) {
  long long n;
  std::cin >> n;
  std::cout << last_digit_of_fibonacci(n) * last_digit_of_fibonacci(n + 1) % 10 << std::endl;
  return 0;
}
