// https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/practice-problems/algorithm/monk-and-nice-strings-3/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_lex_small(string a, string b) {
  int n = min(a.length(), b.length());
  for (int i = 0; i < n; ++i) {
    if (a[i] < b[i]) {
      return true;
    }
    if (a[i] > b[i]) {
      return false;
    }
  }
  if (a.length() < b.length()) {
    return true;
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  getchar();
  vector<string> list(n);
  for (int i = 0; i < n; ++i) {
    cin >> list[i];
    getchar();
  }
  for (int i = 0; i < n; ++i) {
    int count = 0;
    for (int j = 0; j < i; ++j) {
      if (is_lex_small(list[j], list[i])) {
        ++count;
      }
    }
    cout << count << endl;
  }
  return 0;
}
