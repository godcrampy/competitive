#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getVal() {
  char a, b, c;
  cin >> a >> b >> c;
  if (b == '+') {
    return 1;
  }
  return -1;
}

void solve(int n) {
  char a, b, c;
  int x = 0;
  while (n--) {
    x += getVal();
  }
  cout << x << '\n';
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  solve(t);
  return 0;
}
