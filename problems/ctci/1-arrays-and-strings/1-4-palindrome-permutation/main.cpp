#include <iostream>
#include <unordered_set>

using namespace std;

bool palindromePermutationSet(string &s) {
  // * Time: O(|s|)
  // *Space: O(1) 128 max
  // to lowercase
  for (auto &c : s) {
    if (c >= 'A' && c <= 'Z') {
      c += 'a' - 'A';
    }
  }

  unordered_set<char> u;
  for (auto c : s) {
    if (c != ' ') {
      if (u.find(c) == u.end())
        u.insert(c);
      else
        u.erase(c);
    }
  }

  return u.size() <= 1;
}

bool palindromePermutationBit(string &s) {
  // * Time: O(|s|)
  // *Space: O(1) [Assumin only ascii]
  // to lowercase
  for (auto &c : s) {
    if (c >= 'A' && c <= 'Z') {
      c += 'a' - 'A';
    }
  }

  int u = 0;
  for (auto c : s) {
    if (c != ' ') {
      int mask = 1 << c;
      if (u & mask) {
        // toggle to 0
        u &= ~mask;
      } else {
        u |= mask;
      }
    }
  }

  return !(u & (u - 1));  // is power of 2 including 0
}

int main(int argc, char const *argv[]) {
  string s = "cc";
  cout << palindromePermutationSet(s) << " " << palindromePermutationBit(s)
       << endl;
  return 0;
}
