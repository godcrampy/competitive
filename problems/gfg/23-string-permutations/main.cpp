#include <algorithm>
#include <iostream>
using namespace std;

void solve() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());

  do {
    cout << s << " ";
  } while (next_permutation(s.begin(), s.end()));
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
