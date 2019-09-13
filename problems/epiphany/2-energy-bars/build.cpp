#include <iostream>
#include <vector>
#include <algorithm>

class Pair
{
public:
  long final;
  long initial;
  Pair(long a, long b) : final{a}, initial{b} {};
  long get_difference() const { return final - initial; }
  bool operator<(const Pair &obj)
  {
    return (this->get_difference() > obj.get_difference()) ? true : false;
  }
};

bool test_pairs(const Pair &a, const Pair &b)
{
  if (a.initial <= b.initial && a.final < b.final)
    return true;
  if (b.initial <= a.initial && b.final < a.final)
    return true;
  return false;
}

int number_of_bars(std::vector<Pair> &list)
{
  std::vector<Pair> final;
  final.push_back(list.back());
  list.pop_back();
  while (list.size() > 0)
  {
    bool flag = true;
    Pair test = list.back();
    list.pop_back();
    for (Pair i : final)
    {
      if (!test_pairs(i, test))
      {
        flag = false;
        break;
      }
    }
    if (flag)
      final.push_back(test);
  }
  return final.size();
}

int main(int argc, char const *argv[])
{
  int n = 0;
  std::cin >> n;
  std::vector<Pair> list;
  for (int i = 0; i < n; i++)
  {
    long initial, final;
    std::cin >> initial >> final;
    list.push_back(Pair(final, initial));
  }
  std::sort(list.begin(), list.end());
  std::cout << number_of_bars(list) << std::endl;
  return 0;
}
