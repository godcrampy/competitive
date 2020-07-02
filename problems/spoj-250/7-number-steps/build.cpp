#include <iostream>

using namespace std;

bool isValid(int x, int y) { return x == y || x - y == 2 ? true : false; }

int getNumber(int x, int y) { return x % 2 == 0 ? x + y : x + y - 1; }

int main(int argc, char const *argv[]) {
  int t, x, y;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    cin >> x >> y;
    if (isValid(x, y))
      cout << getNumber(x, y) << endl;
    else
      cout << "No Number" << endl;
  }
  return 0;
}
