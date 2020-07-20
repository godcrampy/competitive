#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string rotateLeft(string s) {}

void solve() {
  string og, rotated;
  cin >> og >> rotated;

  int j = 2, i = 0;

  bool yes = true;
  while (i < og.length()) {
    j %= og.length();
    if (og[i] != rotated[j]) {
      yes = false;
      break;
    }
    ++i;
    ++j;
  }
  if (yes) {
    cout << 1 << endl;
    return;
  }

  j = og.length() - 2;
  i = 0;

  yes = true;
  while (i < og.length()) {
    j %= og.length();
    if (og[i] != rotated[j]) {
      yes = false;
      break;
    }
    ++i;
    ++j;
  }
  if (yes) {
    cout << 1 << endl;
    return;
  }
  cout << 0 << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
