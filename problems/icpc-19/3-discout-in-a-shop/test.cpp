#include <iostream>
#include <string>
using namespace std;

void buildLowestNumberRec(string str, int n, string &res)
{
  if (n == 0)
  {
    res.append(str);
    return;
  }

  int len = str.length();

  if (len <= n)
    return;

  int minIndex = 0;
  for (int i = 1; i <= n; i++)
    if (str[i] < str[minIndex])
      minIndex = i;

  res.push_back(str[minIndex]);

  string new_str = str.substr(minIndex + 1, len - minIndex);

  buildLowestNumberRec(new_str, n - minIndex, res);
}

string buildLowestNumber(string str, int n)
{
  string res = "";

  buildLowestNumberRec(str, n, res);

  return res;
}

int main()
{
  int n = 1;

  int t;
  std::cin >> t;
  getchar();
  for (auto _ = 0; _ < t; ++_)
  {
    std::string input;
    std::getline(std::cin, input);
    cout << stol(buildLowestNumber(input, n)) << std::endl;
  }
  return 0;
}