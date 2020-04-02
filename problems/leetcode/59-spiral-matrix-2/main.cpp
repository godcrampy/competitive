#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
  vector<vector<int>> matrix(n, vector<int>(n, 0));

  int rowBegin = 0;
  int rowEnd = n - 1;
  int colBegin = 0;
  int colEnd = n - 1;
  int count = 1;
  while (rowBegin <= rowEnd && colBegin <= colEnd) {
    // Traverse Right
    for (int j = colBegin; j <= colEnd; j++) {
      matrix[rowBegin][j] = count++;
    }
    rowBegin++;

    // Traverse Down
    for (int j = rowBegin; j <= rowEnd; j++) {
      matrix[j][colEnd] = count++;
    }
    colEnd--;

    if (rowBegin <= rowEnd) {
      // Traverse Left
      for (int j = colEnd; j >= colBegin; j--) {
        matrix[rowEnd][j] = count++;
      }
    }
    rowEnd--;

    if (colBegin <= colEnd) {
      // Traver Up
      for (int j = rowEnd; j >= rowBegin; j--) {
        matrix[j][colBegin] = count++;
      }
    }
    colBegin++;
  }
  return matrix;
}