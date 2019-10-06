#include <iostream>
#include <vector>

/**
 *
 * [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] // indices
 * [2, 1, 1, 3, 2, 3, 4, 5, 6, 7] // array
 * [2, 3, 1, 7, 2, 5, 4, 21, 6, 13] // BIT
 * * https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
 * * https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/
 * * https://www.hackerearth.com/practice/notes/binary-indexed-tree-or-fenwick-tree/ 
 */

auto print_vector(std::vector<int> vector)
{
  for (auto number : vector)
    std::cout << number << " ";
  std::cout << std::endl;
}
inline auto last_set_bit(int number)
{
  return number - (number & (-number));
}

inline auto parent(int number)
{
  return number + (number & (-number));
}

auto make_BIT(std::vector<int> &array, std::vector<int> &BIT)
{
  // works
  // * Assumes BIT and Array are 1 indexed
  // ? O(n)
  BIT = {0};
  int size = array.size();
  for (auto i = 1; i < size; ++i)
  {
    int start = last_set_bit(i), sum = 0;
    for (auto j = start + 1; j <= i; ++j)
      sum += array.at(j);
    BIT.push_back(sum);
  }
}

auto get_sum(std::vector<int> &BIT, int position)
{
  // works
  // * Assumes 1 indexed BIT
  // ? O(log(n))
  if (position == 0)
    return 0;
  return BIT.at(position) + get_sum(BIT, last_set_bit(position));
}

auto update_BIT(std::vector<int> &BIT, int position, int value)
{
  // works
  // * Assumes 1 indexed BIT
  // ? O(log(n))
  if (position >= BIT.size())
    return 0;
  BIT.at(position) += value;
  update_BIT(BIT, parent(position), value);
  return 0;
}

int main(int argc, char const *argv[])
{
  std::vector<int> array = {0};
  int size = 0;
  std::cout << "Enter size of array :";
  std::cin >> size;
  std::vector<int> BIT(size + 1, 0);
  for (auto i = 0; i < size; ++i)
  {
    int temp;
    std::cin >> temp;
    array.push_back(temp);
    update_BIT(BIT, i + 1, temp);
  }
  print_vector(BIT);
  return 0;
}
