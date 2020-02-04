// https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/practice-problems/algorithm/old-keypad-in-a-foreign-land-24/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char const *argv[]) {
  // * Input
  int n, k;
  using namespace std;
  cin >> n;
  vector<int> freq(n);
  for (int i = 0; i < n; ++i) {
    cin >> freq[i];
  }
  cin >> k;
  vector<int> keys(k);
  for (int i = 0; i < k; ++i) {
    cin >> keys[i];
  }

  //* Check sum
  int sum = accumulate(keys.begin(), keys.end(), 0);
  if (sum < n) {
    cout << -1 << endl;
    return 0;
  }

  sort(freq.begin(), freq.end(), greater<int>());
  int cost = 0, i = 0, iter = 1;
  // i: number of chars typed
  while (true) {
    for (int j = 0; j < k; ++j) {
      if (keys[j] != 0) {
        --keys[j];
        cost += iter * freq[i];
        ++i;
        if (i == n) {
          cout << cost << endl;
          return 0;
        }
      }
    }
    ++iter;
  }
  cout << cost << endl;
  return 0;
}
