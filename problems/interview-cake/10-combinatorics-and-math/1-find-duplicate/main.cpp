#include <iostream>
#include <vector>

using namespace std;

// ! IMP

unsigned int findRepeat(const vector<unsigned int>& numbers) {
  // find the number that appears twice
  int sum = 0;
  for (auto n : numbers) {
    sum += n;
  }

  int n = numbers.size() - 1;

  int expectedSum = (n * (n + 1)) / 2;

  return sum - expectedSum;
}
