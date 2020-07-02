#include <vector>

using namespace std;

vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
  int sum = 0;

  for (int n : A) {
    if (n % 2 == 0) sum += n;
  }

  vector<int> res;

  for (auto query : queries) {
    int val = query[0];
    int i = query[1];

    if (A[i] % 2 == 0) {
      sum -= A[i];
    }
    A[i] += val;
    if (A[i] % 2 == 0) {
      sum += A[i];
    }
    res.push_back(sum);
  }
  return res;
}