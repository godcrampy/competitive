#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int steps = 0;
  while (true) {
    // find min and check if all equal
    int min = a[0];
    bool change = false;
    for (int i = 0; i < n; ++i) {
      if (a[i] != min) {
        change = true;
      }
      if (a[i] < min) {
        min = a[i];
      }
    }
    if (!change) {
      cout << steps << endl;
      break;
    }
    if (min < 0) {
      cout << -1 << endl;
      break;
    }
    // subtract the rest till min
    for (int i = 0; i < n; ++i) {
      if (a[i] > min) {
        int diff = a[i] - min;
        if (b[i] == 0) {
          continue;
        }
        int times = diff / b[i];
        steps += times;
        a[i] -= times * b[i];
        while (a[i] > min) {
          ++steps;
          a[i] -= b[i];
        }
      }
    }
  }
  return 0;
}
