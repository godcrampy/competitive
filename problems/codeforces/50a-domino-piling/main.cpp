#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(int m, int n) { cout << (m * n) / 2 << '\n'; }

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
  cin >> m >> n;
  solve(m, n);
  return 0;
}
