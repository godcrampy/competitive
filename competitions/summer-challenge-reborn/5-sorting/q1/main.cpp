#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  unordered_map<int, unordered_set<int>> map;  // value -> {index1, index2}
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (map.find(arr[i]) == map.end()) {
      // not found
      map.insert({arr[i], {i}});
    } else {
      // found
      map[arr[i]].insert(i);
    }
  }

  sort(arr.begin(), arr.end());

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += abs(i - *(map[arr[i]].begin()));
    map[arr[i]].erase(map[arr[i]].begin());
  }

  sum = sum / 2;
  if (sum <= k) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
