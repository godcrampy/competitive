#include <vector>

using namespace std;

bool is_self_dividing(int n) {
  int reduce = n;
  while (reduce > 0) {
    int a = reduce % 10;
    if (a == 0 || n % a > 0) return false;
    reduce /= 10;
  }
  return true;
}

vector<int> selfDividingNumbers(int left, int right) {
  int count = 0;
  vector<int> res;
  for (int i = left; i <= right; ++i) {
    if (is_self_dividing(i)) res.push_back(i);
  }
  return res;
}
