#include <vector>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& A) {
  if (A.size() == 0) {
    return {};
  }
  vector<vector<int>> B(A[0].size(), vector<int>(A.size(), 0));
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < A[i].size(); ++j) {
      swap(A[i][j], B[j][i]);
    }
  }
  return B;
}