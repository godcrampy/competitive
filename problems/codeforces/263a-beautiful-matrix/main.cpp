#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve() {
  vector<vector<int>> grid(5, vector<int>(5));
  int x, y, val;
  for (int x = 0; x < 5; ++x) {
    for (int y = 0; y < 5; ++y) {
      cin >> grid[x][y];
      if (grid[x][y] == 1) {
        val = (abs(2 - x) + abs(2 - y));
      }
    }
  }
  return val;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << solve() << '\n';
  return 0;
}
