#include <iostream>
#include <set>

using namespace std;

bool is_string_permutation_palindrome(const string& s) {
  set<char> store;
  for (auto c : s) {
    if (c == ' ') {
      continue;
    }
    if (store.find(c) == store.end()) {
      store.insert(c);
    } else {
      store.erase(c);
    }
  }
  return store.size() <= 1;
}

void toggle_bit(long& n, int index) {
  long mask = 1 << index;
  // xor toggles the mask bit
  n ^= mask;
}

bool is_string_permutation_palindrome_advanced(const string& s) {
  long store = 0;
  for (auto c : s) {
    if (c == ' ') {
      continue;
    }
    toggle_bit(store, c - 'a');
  }
  return ((store - 1) & store) == 0;
}

int main(int argc, char const* argv[]) {
  string s = "tact coa";
  cout << is_string_permutation_palindrome(s) << endl;
  cout << is_string_permutation_palindrome_advanced(s) << endl;
  return 0;
}
