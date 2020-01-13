#include <iostream>

using namespace std;

string urlify_string(string& s, int true_length) {
  // find number of spaces
  int space_count = 0;
  for (auto i = 0; i < true_length; ++i) {
    if (s[i] == ' ') {
      ++space_count;
    }
  }

  // second counter
  int final_index = true_length + 2 * space_count;
  // i is the first counter
  for (auto i = true_length - 1; i >= 0; --i) {
    if (s[i] == ' ') {
      s[final_index - 1] = '0';
      s[final_index - 2] = '2';
      s[final_index - 3] = '%';
      final_index -= 3;
    } else {
      s[final_index - 1] = s[i];
      --final_index;
    }
  }
  return s;
}

int main(int argc, char const* argv[]) {
  string s = "pan cakes  ";
  cout << urlify_string(s, 9) << endl;
  return 0;
}
