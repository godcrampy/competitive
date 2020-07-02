#include <iostream>

using namespace std;

bool isAP(int x, int y, int z) { return x + z == 2 * y; }

bool isGP(int x, int y, int z) { return x * z == y * y; }

int main(int argc, char const *argv[]) {
  int x, y, z;
  while (true) {
    cin >> x >> y >> z;
    if (x == 0 && y == 0 && z == 0) break;
    if (isAP(x, y, z)) cout << "AP " << z + y - x << endl;
    if (isGP(x, y, z)) cout << "GP " << z * y / x << endl;
  }
  return 0;
}
