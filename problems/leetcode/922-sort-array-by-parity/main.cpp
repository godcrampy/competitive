#include <algorithm>
#include <vector>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
  sort(A.begin(), A.end(), [](int a, int b) { return a % 2 > b % 2; });
  // odd first

  int l = 0;
  int r = A.size() - 1;
  while (l < r) {
    swap(A[l], A[r]);
    l += 2;
    r -= 2;
  }
  return A;
}