#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::pair<int, double> pair;

bool lesser(const pair &p1, const pair &p2)
{
  return (static_cast<double>(p1.second) > p2.second);
}

double rank(int number)
{
  auto string = std::to_string(number);
  double final = string[0] - '0';
  int length = string.length();
  double power = 0.1;
  for (auto i = 1; i < length; ++i)
  {
    int difference = string[i] - string[i - 1];
    if (difference < 0)
      final += power * 2;
    else if (difference > 0)
      final += power * 7;
    else
      final += power * 5;
    power /= 10;
  }
  final += power * 5.55;
  return final;
}

void print_salary(std::vector<pair> &numbers)
{
  std::sort(numbers.begin(), numbers.end(), lesser);
  for (auto pair : numbers)
    std::cout << pair.first;
  std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
  int n;
  std::cin >> n;
  std::vector<pair> numbers;
  for (int i = 0; i < n; ++i)
  {
    int temp;
    std::cin >> temp;
    numbers.push_back({temp, rank(temp)});
  }
  print_salary(numbers);
  return 0;
}
