#ifndef _UTIL_HPP_
#define _UTIL_HPP_
#include <algorithm>
#include <iostream>
#include <vector>

void print_yes_or_no(std::vector<int> &sequence) {
  int number_of_mobiles = sequence.size();
  std::vector<int> stack, sorted_sequence;
  std::sort(sorted_sequence.begin(), sorted_sequence.end());
  for (auto i = 0; i < number_of_mobiles - 1; ++i) {
    if (sequence.at(i) > sequence.at(i + 1)) {
      stack.push_back(sequence.at(i));
      sequence.erase(sequence.begin() + i);
    }
  }
  while (stack.size() != 0) {
    sequence.push_back(*stack.end());
    stack.pop_back();
  }
  if (sorted_sequence == sequence)
    std::cout << "yes" << std::endl;
  else
    std::cout << "no" << std::endl;
}

#endif