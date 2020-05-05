#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool hasPalindromePermutation(const string& str) {
  // check if any permutation of the input is a palindrome
  unordered_set<char> s;

  for (char c : str) {
    if (s.find(c) == s.end()) {
      // not found
      s.insert(c);
    } else {
      // found
      s.erase(c);
    }
  }

  return s.size() <= 1;
}
