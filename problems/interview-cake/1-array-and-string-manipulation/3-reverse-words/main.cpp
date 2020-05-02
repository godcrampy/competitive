#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// ! IMP

bool move_to_next_word(const string& message, int& l, int& r) {
  // returns false if out of bounds
  int length = message.length();
  while (l < length && message[l] != ' ') {
    ++l;
  }
  // on space or l == length
  ++l;
  if (l >= length) return false;
  r = l;
  while (r < length && message[r] != ' ') {
    ++r;
  }
  --r;
  return true;
}

void reverseWords(string& message) {
  // decode the message by reversing the words
  // reverse words
  reverse(message.begin(), message.end());

  // reverse individual words
  int l = 0;
  int r = 0;
  int length = message.length();
  // move r for the first time
  while (r < length && message[r] != ' ') {
    ++r;
  }
  --r;

  reverse(message.begin() + l, message.begin() + r + 1);
  while (move_to_next_word(message, l, r)) {
    reverse(message.begin() + l, message.begin() + r + 1);
  }
}
