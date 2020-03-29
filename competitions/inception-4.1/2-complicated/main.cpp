#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;

  cin >> t;

  for (int _ = 0; _ < t; ++_) {
    double x, y, z;
    cin >> x >> y >> z;

    if (y > x && y > z) {
      cout << ceil((x + y + z) / 3) << endl;
    } else {
      int a = (x + y) / 2;
      int b = (a + z) / 2;
      int c = (y + z) / 2;
      int d = (x + c) / 2;
      cout << min(b, d) + 1 << endl;
    }
  }
  return 0;
}
