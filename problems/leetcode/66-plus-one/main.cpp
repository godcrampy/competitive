#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
  bool allNine = true;
  for (auto n : digits) {
    if (n != 9) {
      allNine = false;
      break;
    }
  }
  if (allNine) {
    vector<int> v(digits.size() + 1);
    v[0] = 1;
    return v;
  }

  int i = digits.size() - 1;
  while (true) {
    if (digits[i] == 9) {
      digits[i] = 0;
      --i;
    } else {
      ++digits[i];
      break;
    }
  }
  return digits;
}