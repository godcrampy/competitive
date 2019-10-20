#include <iostream>
#include <vector>

std::vector<int> multiply_polynomial_naive(const std::vector<int> &a, const std::vector<int> &b)
{
  int length = a.size();
  std::vector<int> final(2 * length - 1, 0);
  for (auto i = 0; i < length; ++i)
    for (auto j = 0; j < length; ++j)
      final[i + j] += a[i] * b[j];
  return final;
}

int main(int argc, char const *argv[])
{
  std::vector<int> a = {3, 2, 5}, b = {5, 1, 2};
  auto final = multiply_polynomial_naive(a, b);
  for (auto number : final)
    std::cout << number << " ";
  std::cout << std::endl;
  return 0;
}
