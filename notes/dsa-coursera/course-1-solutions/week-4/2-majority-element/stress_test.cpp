#include <iostream>
#include <vector>
#include <stdlib.h>

int count_of_element(const std::vector<long> &vector, int start, int end, long key)
{
  int count = 0;
  for (auto i = start; i <= end; ++i)
    if (vector[i] == key)
      ++count;
  return count;
}

int does_majority_element_exist(const std::vector<long> &vector, int start, int end)
{
  // returns the position of the majority element if is exits, else returns -1
  if (end == start)
    return start;
  if (end - start == 1)
    return vector[start] == vector[end] ? start : -1;
  int length = end - start + 1;
  int mid = length / 2 - 1;
  int majority_left_position = does_majority_element_exist(vector, start, start + mid);
  int majority_right_position = does_majority_element_exist(vector, start + mid + 1, end);
  int count_left = 0, count_right = 0;
  if (majority_left_position != -1)
    count_left = count_of_element(vector, start, end, vector[majority_left_position]);
  if (majority_right_position != -1)
    count_right = count_of_element(vector, start, end, vector[majority_right_position]);
  if (count_left > length / 2 && count_right > length / 2)
    return count_left > count_right ? majority_left_position : majority_right_position;
  if (count_left > length / 2)
    return majority_left_position;
  if (count_right > length / 2)
    return majority_right_position;
  return -1;
}

int main(int argc, char const *argv[])
{
  while (true)
  {
    int n = rand() % 100000 + 1;
    // std::cin >> n;
    std::vector<long> vector;
    std::cout << "n: " << n << std::endl;
    for (auto i = 0; i < n; ++i)
    {
      long temp = rand() % 1000000000 + 1;
      // std::cin >> temp;
      vector.push_back(temp);
    }
    for (auto number : vector)
      std::cout << number << " ";
    std::cout << std::endl;
    std::cout << does_majority_element_exist(vector, 0, n - 1) << std::endl;
  }
  return 0;
}