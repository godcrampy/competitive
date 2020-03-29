#include <limits.h>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int number_of_steps_rec(vector<vector<int>> &board, vector<vector<bool>> &visited, int x, int y, bool power, char under) {
  int r = board.size();
  int c = board[0].size();
  if (x == c || y == r || visited[x][y] == true) {
    return INT_MAX;
  }
  if (x == c - 1 && y == r - 1) {
    return 0;
  }
  if (under == 'x') {
  }
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> board(r, vector<int>(c));
    vector<vector<int>> visited(r, vector<int>(c, false));
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        cin >> board[i][j];
      }
    }
  }
  return 0;
}
