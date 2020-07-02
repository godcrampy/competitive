#include <iostream>
#include <vector>

using namespace std;

void rotate_4(long& a, long& b, long& c, long& d) {
  long temp = b;
  b = a;
  a = c;
  c = temp;
  temp = d;
  d = a;
  a = temp;
}

void rotate_matrix(vector<vector<long>>& m) {
  // nxn matrix
  int n = m.size();
  // l = number of layers
  int l = (n + 1) / 2;
  for (int i = 0; i < l; ++i) {
    for (int j = i; j < n - i - 1; ++j) {
      cout << j << endl;
      rotate_4(m[i][j], m[j][n - i - 1], m[n - i - 1][n - j - 1],
               m[n - j - 1][i]);
    }
  }
}

int main() {
  vector<vector<long>> image = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<vector<long>> image_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  rotate_matrix(image);
  for (auto v : image) {
    for (auto n : v) {
      cout << n << " ";
    }
    cout << endl;
  }
  return 0;
}
