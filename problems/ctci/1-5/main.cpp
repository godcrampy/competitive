#include <iostream>

using namespace std;

bool max_one_char_diff(string a, string b) {
  bool edit = false;
  for (auto i = 0; i < a.length(); ++i) {
    if (a[i] != b[i]) {
      if (edit) {
        return false;
      }
      edit = true;
    }
  }
  return true;
}

bool max_one_char_delete(string a, string b) {
  // a is longer
  int skip = 0;
  for (auto i = 0; i < a.length(); ++i) {
    if (a[i] != b[i - skip]) {
      if (skip) {
        return false;
      }
      ++skip;
    }
  }
  return true;
}

bool is_one_away(string a, string b) {
  if (a.length() == b.length()) {
    return max_one_char_diff(a, b);
  }
  if (a.length() - b.length() == 1) {
    return max_one_char_delete(a, b);
  }
  if (b.length() - a.length() == 1) {
    return max_one_char_delete(b, a);
  }
  return false;
}

int main(int argc, char const* argv[]) {
  string a = "pale", b = "bake";
  cout << is_one_away(a, b) << endl;
  return 0;
}
