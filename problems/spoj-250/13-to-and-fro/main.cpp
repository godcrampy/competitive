#include <iostream>
#include <string>

#include "util.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int columns;
  std::string cipher;
  while (true) {
    cin >> columns;
    if (columns == 0) break;
    getchar();
    getline(cin, cipher);
    int rows = cipher.length() / columns;
    vector<vector<char>> matrix;
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) matrix.at(i).resize(columns);
    fill_matrix(matrix, rows, columns, cipher);
    decipher_text(matrix, rows, columns);
  }
  return 0;
}
