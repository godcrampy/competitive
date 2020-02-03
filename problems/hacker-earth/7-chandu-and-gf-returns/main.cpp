// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/chandu-and-his-girlfriend-returns/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    int n, m;
    cin >> m >> n;
    vector<int> arr1(m), arr2(n), arr3(m + n);
    for (int i = 0; i < m; ++i) {
      cin >> arr1[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> arr2[i];
    }
    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin(), [](const int &a, const int &b) {
      return b < a;
    });
    for (auto n : arr3) {
      cout << n << " ";
    }
    cout << endl;
  }
  return 0;
}
