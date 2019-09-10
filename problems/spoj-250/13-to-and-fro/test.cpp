#include <iostream>
#include "util.h"
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
  int rows = 7;
  int columns = 5;
  vector<vector<char>> matrix;
  matrix.resize(rows);
  for (int i = 0; i < rows; i++)
    matrix.at(i).resize(columns);
  fill_matrix(matrix, rows, columns, "toioynnkpheleaigshareconhtomesnlewx");
  print_matrix(matrix, rows, columns);
  decipher_text(matrix, rows, columns);
  return 0;
}
