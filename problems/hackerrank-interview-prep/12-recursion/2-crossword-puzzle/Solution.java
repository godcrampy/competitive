import java.util.*;

public class Solution {
  static class Res {
    char[][] grid;
    boolean b;
    Res(char[][] grid, boolean b) {
      this.grid = grid;
      this.b = b;
    }
  }

  static Res solve(char[][] crossword, String[] words, int index) {
    if (index >= words.length) {
      Res r = new Res(crossword, true);
      return r;
    }

    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        // check horizontal fitting
        boolean fits = true;
        for (int k = 0; k < words[index].length(); ++k) {
          if (j + k >= 10
              || !(crossword[i][j + k] == '-' || crossword[i][j + k] == words[index].charAt(k))) {
            fits = false;
            break;
          }
        }

        if (fits) {
          // it fits at i, j;
          char[][] grid = new char[10][10];
          for (int p = 0; p < 10; ++p) {
            for (int q = 0; q < 10; ++q) {
              grid[p][q] = crossword[p][q];
            }
          }
          for (int k = 0; k < words[index].length(); ++k) {
            grid[i][j + k] = words[index].charAt(k);
          }
          Res r = solve(grid, words, index + 1);
          if (r.b) {
            crossword = grid;
            return r;
          }
        }

        // check vertical fitting
        fits = true;
        for (int k = 0; k < words[index].length(); ++k) {
          if (i + k >= 10
              || !(crossword[i + k][j] == '-' || crossword[i + k][j] == words[index].charAt(k))) {
            fits = false;
            break;
          }
        }

        if (fits) {
          // it fits at i, j;
          char[][] grid = new char[10][10];
          for (int p = 0; p < 10; ++p) {
            for (int q = 0; q < 10; ++q) {
              grid[p][q] = crossword[p][q];
            }
          }
          for (int k = 0; k < words[index].length(); ++k) {
            grid[i + k][j] = words[index].charAt(k);
          }
          Res r = solve(grid, words, index + 1);
          if (r.b) {
            crossword = grid;
            return r;
          }
        }
      }
    }
    Res r = new Res(crossword, false);
    return r;
  }
  // Complete the crosswordPuzzle function below.
  static String[] crosswordPuzzle(String[] crossword, String words) {
    List<String> w = new ArrayList<>();
    int l = 0;
    while (l < words.length()) {
      int length = 0;
      while (l + length < words.length() && words.charAt(l + length) != ';') {
        ++length;
      }
      w.add(words.substring(l, l + length));
      l += length + 1;
    }

    // String[] to char[][]
    char[][] m = new char[10][10];

    for (int i = 0; i < 10; ++i) {
      m[i] = crossword[i].toCharArray();
    }

    String[] wa = new String[w.size()];
    for (int i = 0; i < w.size(); ++i) {
      wa[i] = w.get(i);
    }

    m = solve(m, wa, 0).grid;

    for (int i = 0; i < 10; ++i) {
      crossword[i] = new String(m[i]);
    }

    return crossword;
  }
}
