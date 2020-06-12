#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  unordered_map<int, pair<long, int>> rows, columns;  // row_number => {color, priority}
  for (int i = 0; i < n; ++i) {
    rows[i] = {0, -1};
  }

  for (int j = 0; j < m; ++j) {
    columns[j] = {0, -1};
  }

  for (int i = 0; i < k; ++i) {
    int type, index;
    long color;
    cin >> type >> index >> color;
    --index;  // zero index
    if (type == 1) {
      // make row to color
      rows[index] = {color, i};
    } else {
      columns[index] = {color, i};
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (rows[i].second > columns[j].second) {
        cout << rows[i].first << " ";
      } else {
        cout << columns[j].first << " ";
      }
    }
    cout << endl;
  }
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
