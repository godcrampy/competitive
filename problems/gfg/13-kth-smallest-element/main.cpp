#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// * T: O(1), S: O(logn) [recursion calls]
// * Worst Case: O(n^2) time
int quickSort(vector<int>& v, int l, int r, int k) {
  if (l > r) {
    return -1;
  }
  int pivot = rand() % (r - l) + l;
  int x = v[pivot];
  swap(v[pivot], v[r - 1]);
  int j = l;
  for (int i = l; i < r; ++i) {
    if (v[i] < x) {
      swap(v[i], v[j++]);
    }
  }
  swap(v[j], v[r - 1]);
  if (j < k) {
    return quickSort(v, j + 1, r, k);
  }

  if (j > k) {
    return quickSort(v, l, j, k);
  }

  return v[j];
}

int quickSortApproach(vector<int> v, int k) {
  return quickSort(v, 0, v.size(), k);
}

void solve() {
  // * T: O(nlogn) S: O(1)
  long n, k;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  cin >> k;
  sort(v.begin(), v.end());
  cout << v[k - 1] << endl;
  // cout << quickSortApproach(v, k - 1) << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
