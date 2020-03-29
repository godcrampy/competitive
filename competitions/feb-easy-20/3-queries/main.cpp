#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, q;
  cin >> n >> q;
  vector<long> arr(n, 0);
  int type, l, r, x;
  for (auto i = 0; i < q; ++i) {
    cin >> type;
    if (type == 1) {
      cin >> l >> r >> x;
      for (int j = l; j <= r; ++j) {
        arr[j] |= x;
      }
    } else if (type == 2) {
      cin >> l >> r >> x;
      for (int j = l; j <= r; ++j) {
        arr[j] &= x;
      }
    } else if (type == 3) {
      cin >> l >> r >> x;
      for (int j = l; j <= r; ++j) {
        arr[j] ^= x;
      }
    } else if (type == 5) {
      cin >> l >> r;
      long ret = arr[l];
      for (int j = l + 1; j <= r; ++j) {
        ret ^= arr[j];
      }
      cout << ret << endl;
    } else {
      cin >> l >> r;
      long ret = 0;
      for (int j = l; j <= r; ++j) {
        ret += arr[j];
      }
      cout << ret << endl;
    }
  }
  return 0;
}
