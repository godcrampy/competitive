// https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/sort-it-out/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, char const* argv[]) {
  int m;
  cin >> m;
  vector<pair<int, int>> arr(m);
  for (int i = 0; i < m; ++i) {
    int temp;
    cin >> temp;
    arr[i] = {i, temp};
  }
  stable_sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
  });
  for (auto p : arr) {
    cout << p.first << " ";
  }
  cout << endl;
  return 0;
}
