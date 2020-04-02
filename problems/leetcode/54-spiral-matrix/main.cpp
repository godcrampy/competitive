#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  if (matrix.size() == 0) return {};

  vector<int> res;

  int rowBegin = 0;
  int rowEnd = matrix.size() - 1;
  int colBegin = 0;
  int colEnd = matrix[0].size() - 1;

  while (rowBegin <= rowEnd && colBegin <= colEnd) {
    // Traverse Right
    for (int j = colBegin; j <= colEnd; j++) {
      res.push_back(matrix[rowBegin][j]);
    }
    rowBegin++;

    // Traverse Down
    for (int j = rowBegin; j <= rowEnd; j++) {
      res.push_back(matrix[j][colEnd]);
    }
    colEnd--;

    if (rowBegin <= rowEnd) {
      // Traverse Left
      for (int j = colEnd; j >= colBegin; j--) {
        res.push_back(matrix[rowEnd][j]);
      }
    }
    rowEnd--;

    if (colBegin <= colEnd) {
      // Traver Up
      for (int j = rowEnd; j >= rowBegin; j--) {
        res.push_back(matrix[j][colBegin]);
      }
    }
    colBegin++;
  }

  return res;
}