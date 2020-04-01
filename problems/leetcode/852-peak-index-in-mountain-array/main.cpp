#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& A) {
  for (int i = 1; i < A.size() - 1; ++i) {
    if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
      return i;
    }
  }
  return A.size() - 1;
}