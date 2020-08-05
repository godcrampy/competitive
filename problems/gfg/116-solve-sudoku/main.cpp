#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool valid(int g[9][9], int i, int j, int n) {
  for (int k = 0; k < 9; ++k) {
    if (g[i][k] == n) return false;
    if (g[k][j] == n) return false;
  }

  int startX = (i / 3) * 3;
  int startY = (j / 3) * 3;
  int endX = startX + 3;
  int endY = startY + 3;

  for (int x = startX; x < endX; ++x)
    for (int y = startY; y < endY; ++y)
      if (g[x][y] == n) return false;

  return true;
}

bool solveSudoku(int g[9][9], int n) {
  if (n >= 81) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        cout << g[i][j] << " ";
      }
    }
    cout << endl;
    return true;
  };
  int i = n / 9;
  int j = n % 9;

  if (g[i][j] != 0) return solveSudoku(g, n + 1);

  for (int k = 1; k < 10; ++k) {
    if (valid(g, i, j, k)) {
      g[i][j] = k;
      if (solveSudoku(g, n + 1)) return true;
      g[i][j] = 0;
    }
  }

  g[i][j] = 0;
  return false;
}

void solve() {
  int g[9][9];

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      cin >> g[i][j];
    }
  }

  solveSudoku(g, 0);
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
