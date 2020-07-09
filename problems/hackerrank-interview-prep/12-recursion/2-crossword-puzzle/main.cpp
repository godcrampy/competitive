#include <bits/stdc++.h>

using namespace std;

bool solve(vector<string> &crossword, vector<string> &words, int index) {
  // fit all words from index till the end
  if (index >= words.size()) {
    return true;
  }

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      // check horizontal fitting
      bool fits = true;
      for (int k = 0; k < words[index].length(); ++k) {
        if (j + k >= 10 || !(crossword[i][j + k] == '-' ||
                             crossword[i][j + k] == words[index][k])) {
          fits = false;
          break;
        }
      }

      if (fits) {
        // it fits at i, j;
        auto grid = crossword;
        for (int k = 0; k < words[index].length(); ++k) {
          grid[i][j + k] = words[index][k];
        }
        if (solve(grid, words, index + 1)) {
          crossword = grid;
          return true;
        }
      }

      // check vertical fitting
      fits = true;
      for (int k = 0; k < words[index].length(); ++k) {
        if (i + k >= 10 || !(crossword[i + k][j] == '-' ||
                             crossword[i + k][j] == words[index][k])) {
          fits = false;
          break;
        }
      }

      if (fits) {
        // it fits at i, j;
        auto grid = crossword;
        for (int k = 0; k < words[index].length(); ++k) {
          grid[i + k][j] = words[index][k];
        }
        if (solve(grid, words, index + 1)) {
          crossword = grid;
          return true;
        }
      }
    }
  }
  // didn't fit
  return false;
}

// Complete the crosswordPuzzle function below.
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
  // words => vector<words>
  vector<string> w;
  int l = 0;
  while (l < words.length()) {
    int length = 0;
    while (l + length < words.length() && words[l + length] != ';') {
      ++length;
    }
    w.push_back(words.substr(l, length));
    l += length + 1;
  }
  solve(crossword, w, 0);
  return crossword;
}
