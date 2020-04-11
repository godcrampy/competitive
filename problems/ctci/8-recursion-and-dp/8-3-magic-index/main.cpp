#include <iostream>
#include <vector>

using namespace std;

int magic_index(const vector<int>& v, int l, int r) {
  if (l > r) {
    return -1;
  }

  int mid = l + (r - l) / 2;

  if (mid == v[mid]) {
    return mid;
  }

  int left = magic_index(v, l, mid - 1);
  if (left != -1) {
    return left;
  }

  int right = magic_index(v, mid + 1, r);
  return right;
}

int magic_index(const vector<int>& v) {
  return magic_index(v, 0, v.size() - 1);
}

int main(int argc, char const* argv[]) {
  vector<int> v = {-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13};
  cout << magic_index(v) << endl;
  return 0;
}
