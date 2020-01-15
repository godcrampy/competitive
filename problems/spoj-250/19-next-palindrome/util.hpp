#ifndef _UTIL_HPP_
#define _UTIL_HPP_
#include <math.h>
#include <algorithm>
#include <vector>

int length_of_number(long number) {
  // works
  if (!number)
    return 1;
  return std::log10(number) + 1;
}

std::vector<int> number_to_vector(long number) {
  std::vector<int> vector = {};
  while (number != 0) {
    vector.push_back(number % 10);
    number /= 10;
  }
  std::reverse(vector.begin(), vector.end());
  return vector;
}

long vector_to_number(std::vector<int> vector) {
  int size = vector.size();  // length of number
  long number = 0;           // return number
  for (int i = 0; i < size; ++i)
    number += vector.at(i) * std::pow(10, size - i - 1);
  return number;
}

long make_palindrome(long number) {
  // works
  std::vector<int> vector = number_to_vector(number);
  int length = vector.size();             // length of number
  int boundary_index = (length - 1) / 2;  // index of the last number which cannot be edited
  if (length % 2 == 0)
    for (int i = 0; i < length / 2; ++i)
      vector.at(boundary_index + i + 1) = vector.at(boundary_index - i);
  else
    for (int i = 0; i < length / 2; ++i)
      vector.at(boundary_index + i + 1) = vector.at(boundary_index - i - 1);
  return vector_to_number(vector);
}

long next_palindrome(long number) {
  int length = length_of_number(number);
  long proposal = number;               // number to be returned
  long temp = number;                   // copy of number to add numbers too
  int add_position = (length - 1) / 2;  // position to be increased by one
  while (true) {
    proposal = make_palindrome(temp);
    if (proposal > number)
      break;
    temp += pow(10, length - add_position - 1);
  }
  return proposal;
}

#endif