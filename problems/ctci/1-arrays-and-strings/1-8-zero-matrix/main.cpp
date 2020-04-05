#include <iostream>
#include <vector>

using namespace std;

void nullifyRow(vector<vector<int>> &m, int x) {
  for (int i = 0; i < m[0].size(); ++i) {
    m[x][i] = 0;
  }
}

void nullifyColumn(vector<vector<int>> &m, int x) {
  for (int i = 0; i < m.size(); ++i) {
    m[i][x] = 0;
  }
}

void nullifyMatrix(vector<vector<int>> &m) {
  // * Time: O(m*n)
  // * Space: O(m + n)
  // * If matrix was of only ones and zeroes, we ould have used the first row and first column instead of new vectors
  if (m.size() == 0) return;
  vector<bool> rowsZero(m.size(), false);        // which rows to zero
  vector<bool> columnsZero(m[0].size(), false);  // which columns to zero

  for (int i = 0; i < m.size(); ++i) {
    for (int j = 0; j < m[i].size(); ++j) {
      if (m[i][j] == 0) {
        rowsZero[i] = true;
        columnsZero[j] = true;
      }
    }
  }

  for (int i = 0; i < m.size(); ++i) {
    if (rowsZero[i]) nullifyRow(m, i);
  }

  for (int i = 0; i < m[0].size(); ++i) {
    if (columnsZero[i]) nullifyColumn(m, i);
  }
}

void printMatrix(const vector<vector<int>> &m) {
  for (auto v : m) {
    for (auto n : v) {
      cout << n << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> m = {{1, 0, 1},
                           {1, 1, 1},
                           {1, 1, 0},
                           {1, 1, 1}};

  printMatrix(m);
  nullifyMatrix(m);
  printMatrix(m);

  return 0;
}
