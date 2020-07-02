#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// available denominations  = 1, 3, 4

int tri_min(int a, int b, int c) { return min(a, min(b, c)); }

int money_change(int n) {
  vector<int> table(n + 1, 0);
  table[0] = 0;
  for (auto i = 1; i <= n; ++i) {
    int a = table[i - 1];
    int b = i - 3 >= 0 ? table[i - 3] : INT16_MAX;
    int c = i - 4 >= 0 ? table[i - 4] : INT16_MAX;
    table[i] = tri_min(a, b, c) + 1;
  }
  return table[n];
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  cout << money_change(n) << endl;
  return 0;
}
