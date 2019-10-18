#include <iostream>
#include <string>

void build_lowest_recursive(std::string str, std::string &res)
{
  int len = str.length();
  if (len <= 1)
    return;
  int minIndex = 0;
  for (int i = 1; i <= 1; i++)
    if (str[i] < str[minIndex])
      minIndex = i;
  res.push_back(str[minIndex]);
  std::string new_str = str.substr(minIndex + 1, len - minIndex);
  build_lowest_recursive(new_str, res);
}

std::string build_lowest(std::string str)
{
  std::string res = "";
  build_lowest_recursive(str, res);
  return res;
}

int main(int argc, char const *argv[])
{
  int t;
  std::cin >> t;
  getchar();
  for (auto _ = 0; _ < t; ++_)
  {
    std::string input;
    std::getline(std::cin, input);
    std::cout << std::stol(build_lowest(input)) << std::endl;
  }
  return 0;
}
