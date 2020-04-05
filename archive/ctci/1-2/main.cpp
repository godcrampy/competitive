#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool compare_strings_slow(string a, string b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  return a == b;
}

bool compare_strings(string a, string b) {
  if (a.length() != b.length()) {
    return false;
  }
  map<char, int> map_a, map_b;
  // fill a map
  for (auto c : a) {
    if (map_a.find(c) == map_a.end()) {
      // charecter inserted for the first time
      map_a.insert({c, 1});
    } else {
      ++map_a[c];
    }
  }
  // fill b map
  for (auto c : b) {
    if (map_a.find(c) == map_b.end()) {
      // charecter inserted for the first time
      map_b.insert({c, 1});
    } else {
      ++map_b[c];
    }
  }

  return map_a == map_b;
}

int main(int argc, char const *argv[]) {
  string a, b;
  cin >> a >> b;
  cout << compare_strings_slow(a, b) << endl;
  cout << compare_strings(a, b) << endl;
  return 0;
}
