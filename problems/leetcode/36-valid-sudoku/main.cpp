#include <set>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
  for (int i = 0; i < board.size(); i++)  // check row
  {
    set<char> sudoku;
    for (int j = 0; j < board[i].size(); j++) {
      if (board[i][j] == '.') continue;
      if (sudoku.find(board[i][j]) == sudoku.end()) {
        sudoku.insert(board[i][j]);
      } else
        return false;
    }
  }

  for (int col = 0; col < 9; col++)  // check col
  {
    set<char> sudoku;
    for (int row = 0; row < 9; row++) {
      if (board[row][col] == '.') continue;
      if (sudoku.find(board[row][col]) == sudoku.end()) {
        sudoku.insert(board[row][col]);
      } else
        return false;
    }
  }

  vector<vector<int>> dir{{0, 0}, {0, 3}, {0, 6}, {3, 0}, {6, 0},
                          {3, 3}, {3, 6}, {6, 3}, {6, 6}};  // direction
  for (vector<int> it : dir)                                // for each box
  {
    set<char> sudoku;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        char cur = board[i + it[0]][j + it[1]];
        if (cur == '.') continue;
        if (sudoku.find(cur) == sudoku.end()) {
          sudoku.insert(cur);
        } else
          return false;
      }
    }
  }
  return true;
}