#include <iostream>
#include <vector>

using namespace std;

void solve() {
  double x, y, a;
  cin >> x >> y >> a;
  if (y * y == 4 * a * x) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    solve();
  }
  return 0;
}
