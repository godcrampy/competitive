#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
  std::vector<int> godzilla_army, mech_army;
  int godzilla_army_count, mech_army_count;
  std::cin >> godzilla_army_count >> mech_army_count;
  for (auto i = 0; i < godzilla_army_count; ++i)
  {
    int temp;
    std::cin >> temp;
    godzilla_army.push_back(temp);
  }
  for (auto i = 0; i < mech_army_count; ++i)
  {
    int temp;
    std::cin >> temp;
    mech_army.push_back(temp);
  }
  std::sort(godzilla_army.begin(), godzilla_army.end(), std::greater<int>());
  std::sort(mech_army.begin(), mech_army.end(), std::greater<int>());
  while (godzilla_army_count != 0 && mech_army_count != 0)
  {
    if (godzilla_army[godzilla_army_count - 1] < mech_army[mech_army_count - 1])
    {
      godzilla_army.pop_back();
      --godzilla_army_count;
    }
    else
    {
      mech_army.pop_back();
      --mech_army_count;
    }
  }
  if (mech_army_count)
    std::cout << "Mech" << std::endl;
  else
    std::cout << "Godzilla" << std::endl;
  return 0;
}
