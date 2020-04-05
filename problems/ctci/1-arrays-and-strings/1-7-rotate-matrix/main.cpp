#include <iostream>
#include <vector>

using namespace std;

// * IMP

void printMatrix(const vector<vector<int>>& m) {
  for (auto v : m) {
    for (auto n : v) {
      cout << n << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void rotateMatrix(vector<vector<int>>& m) {
  // * Time: O(|m|^2)
  // * Space: O(1)
  int n = m.size();

  for (int layer = 0; layer < n / 2; ++layer) {
    int first = layer;
    int last = n - layer - 1;
    for (int i = first; i < last; ++i) {
      int offset = i - first;
      int top = m[first][i];

      m[first][i] = m[last - offset][first];

      m[last - offset][first] = m[last][last - offset];

      m[last][last - offset] = m[i][last];

      m[i][last] = top;
    }
  }
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> a = {{1}};
  vector<vector<int>> b = {{1, 2},
                           {3, 4}};
  vector<vector<int>> c = {{1, 2, 3},
                           {4, 5, 6},
                           {7, 8, 9}};
  vector<vector<int>> d = {{1, 2, 3, 4},
                           {5, 6, 7, 8},
                           {9, 10, 11, 12},
                           {13, 14, 15, 16}};

  printMatrix(a);
  printMatrix(b);
  printMatrix(c);
  printMatrix(d);

  rotateMatrix(a);
  rotateMatrix(b);
  rotateMatrix(c);
  rotateMatrix(d);

  printMatrix(a);
  printMatrix(b);
  printMatrix(c);
  printMatrix(d);

  return 0;
}
