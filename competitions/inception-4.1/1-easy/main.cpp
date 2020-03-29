#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;

  cin >> t;

  for (int _ = 0; _ < t; ++_) {
    int count = 0;
    int x, y, z;
    cin >> x >> y >> z;

    for (int a = 1; a <= x; ++a) {
      for (int b = 1; b <= y; ++b) {
        for (int c = 1; c <= z; ++c) {
          if (a * a + b * b == 4 * c + 3) {
            ++count;
            break;
          }
        }
      }
    }

    cout << count << endl;
  }
  return 0;
}
