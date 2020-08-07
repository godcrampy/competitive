#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int count = 1;
  for (int i = 0; i < 32; ++i) {
    if (n & 1) {
      cout << count << endl;
      return;
    }
    ++count;
    n = n >> 1;
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
