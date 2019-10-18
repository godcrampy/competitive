#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <iterator>

void print_answer(const std::string &string, std::vector<std::set<char>> all_the_ps)
{
  for (int i = 0; i < string.length(); ++i)
  {
    int length_to_check = 1;
    std::set<char> working_p;
    while (true)
    {
      bool flag = false;
      for (auto p : all_the_ps)
      {
        flag = true;
        for (int j = i; j < i + length_to_check; ++j)
        {
          if (p.find(string[j]) == p.end())
          {
            flag = false;
            break;
          }
        }
        if (flag)
        {
          ++length_to_check;
          working_p = p;
          break;
        }
      }
      if (!flag)
      {
        --length_to_check;
        break;
      }
    }
    for (int k = 0; k < string.length(); k++)
    {
      if (all_the_ps[k] == working_p)
      {
        for (int l = 0; l < length_to_check; l++)
        {
          std::cout << k + 1 << " ";
        }
        break;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int t;
  std::cin >> t;
  getchar();
  for (auto _ = 0; _ < t; ++_)
  {
    int n, k;
    std::vector<std::set<char>> vector;
    std::cin >> n >> k;
    getchar();
    getchar();
    std::string string;
    std::getline(std::cin, string);
    for (int m = 0; m < k; ++m)
    {
      std::string temp;
      std::getline(std::cin, temp);
      std::set<char> tempS;
      for (auto n = 0; n < temp.length(); ++n)
      {
        tempS.insert(temp[n]);
      }
      vector.push_back(tempS);
    }
    print_answer(string, vector);
    std::cout << std::endl;
  }
  return 0;
}
