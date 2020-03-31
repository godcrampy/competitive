#include <algorithm>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int>& A) {
  for_each(A.begin(), A.end(), [](int& a) { a *= a; });
  sort(A.begin(), A.end());
  return A;
}