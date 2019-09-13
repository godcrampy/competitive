#include <iostream>
#include <vector>
#include "util.hpp"

int main(int argc, char const *argv[])
{
  long l, n;
  std::cin >> n >> l;
  std::vector<Square> list(n + 1, Square());
  std::vector<long> ladder_positions;
  for (long i = 0; i < l; i++)
  {
    long position, ending;
    std::cin >> position >> ending;
    list.at(position).has_ladder = true;
    list.at(position).ladder_length = ending - position;
    ladder_positions.push_back(position);
  }
  for (long i : ladder_positions)
    std::cout << ways_to_get_to_position(list, 0, i) + ways_to_get_to_last(list, i) << std::endl;
  return 0;
}
