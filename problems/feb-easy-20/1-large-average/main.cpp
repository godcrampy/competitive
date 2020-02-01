#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  long long a, b;
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    cin >> a >> b;
    cout << (a + b) / 2 << endl;
  }
  return 0;
}
