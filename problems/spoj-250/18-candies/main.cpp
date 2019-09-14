#include <iostream>
#include <vector>
#include <numeric>

int main()
{
  int t;
  std::cin >> t;
  for (int _ = 0; _ < t; _++)
  {
    // (A + B)%m = (A%m + B%m)%m
    getchar();
    long n;
    std::cin >> n;
    std::vector<long long> list;
    for (long i = 0; i < n; i++)
    {
      long long input;
      std::cin >> input;
      list.push_back(input % n);
    }
    long long sum = std::accumulate(list.begin(), list.end(), 0);
    if ((sum % n) == 0)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }
  return 0;
}
