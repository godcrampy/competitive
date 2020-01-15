#include <iostream>
#include <string>
#include <vector>

void fill_matrix(std::vector<std::vector<char>> &matrix, int rows, int columns, std::string string) {
  bool fill_left_to_right = true;
  int string_iterator = 0;
  for (int i = 0; i < rows; i++) {
    if (fill_left_to_right)
      for (int j = 0; j < columns; j++) {
        matrix.at(i).at(j) = string[string_iterator];
        string_iterator++;
      }
    else
      for (int j = columns - 1; j >= 0; j--) {
        matrix.at(i).at(j) = string[string_iterator];
        string_iterator++;
      }
    fill_left_to_right = !fill_left_to_right;
  }
}

void print_matrix(std::vector<std::vector<char>> &matrix, int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
      std::cout << matrix.at(i).at(j) << " ";
    std::cout << std::endl;
  }
}

void decipher_text(std::vector<std::vector<char>> matrix, int rows, int columns) {
  for (int i = 0; i < columns; ++i)
    for (int j = 0; j < rows; ++j)
      std::cout << matrix.at(j).at(i);
  std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
  int columns;
  std::string cipher;
  while (true) {
    std::cin >> columns;
    if (columns == 0)
      break;
    getchar();
    getline(std::cin, cipher);
    int rows = cipher.length() / columns;
    std::vector<std::vector<char>> matrix;
    matrix.resize(rows);
    for (int i = 0; i < rows; i++)
      matrix.at(i).resize(columns);
    fill_matrix(matrix, rows, columns, cipher);
    decipher_text(matrix, rows, columns);
  }
  return 0;
}
