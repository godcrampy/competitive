#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
  if (numRows == 0) return {};

  vector<vector<int>> res(numRows, {1});
  for (int i = 1; i < numRows; ++i) {
    vector<int> temp(i + 1, 1);

    for (int j = 1; j < i; ++j) {
      temp[j] = res[i - 1][j] + res[i - 1][j - 1];
    }

    res[i] = temp;
  }
  return res;
}