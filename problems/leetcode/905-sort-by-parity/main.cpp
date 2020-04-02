#include <algorithm>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
  sort(A.begin(), A.end(), [](int a, int b) { return a % 2 < b % 2; });
  return A;
}