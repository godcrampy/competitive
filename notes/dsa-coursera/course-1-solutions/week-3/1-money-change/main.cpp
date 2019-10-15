#include <iostream>

int money_change(int cash)
{
  int coins = 0;
  while (cash > 0)
  {
    if (cash >= 10)
    {
      coins += cash / 10;
      cash = cash % 10;
    }
    else if (cash >= 5)
    {
      coins += cash / 5;
      cash = cash % 5;
    }
    else
    {
      coins += cash;
      cash = 0;
    }
  }
  return coins;
}

int main(int argc, char const *argv[])
{
  int n;
  std::cin >> n;
  std::cout << money_change(n) << std::endl;
  return 0;
}
