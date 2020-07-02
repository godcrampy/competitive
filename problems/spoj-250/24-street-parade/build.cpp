#include <iostream>
#include <stack>
#include <vector>

void print_yes_or_no(std::vector<int> &sequence) {
  std::stack<int> stack;
  bool flag = true;
  int length_of_sequence = sequence.size();
  int current_position = 0,
      actual_position = 1;  // actual number of car at a position
  while (current_position < length_of_sequence) {
    if (sequence.at(current_position) == actual_position) {
      // mobile in the correct position
      ++actual_position;
      ++current_position;
    } else if (!stack.empty() && stack.top() == actual_position) {
      // stack has the required mobile, pop it
      ++actual_position;
      stack.pop();
    } else if (!stack.empty() && sequence.at(current_position) > stack.top()) {
      flag = false;
      break;
    } else {
      // push the current mobile to the stack
      stack.push(sequence.at(current_position));
      ++current_position;
    }
  }
  if (flag)
    std::cout << "yes" << std::endl;
  else
    std::cout << "no" << std::endl;
}

int main() {
  int number_of_mobiles, n;
  while (true) {
    std::cin >> number_of_mobiles;
    if (number_of_mobiles == 0) break;
    std::vector<int> sequence, sorted_sequence;
    for (auto i = 0; i < number_of_mobiles; ++i) {
      std::cin >> n;
      sequence.push_back(n);
    }
    print_yes_or_no(sequence);
  }
  return 0;
}
