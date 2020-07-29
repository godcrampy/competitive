#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> g(m, vector<int>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }

  int x, y;
  cin >> x >> y;
  if (g[0][0] == 0) {
    cout << -1 << endl;
    return;
  }

  if (x == 0 && y == 0) {
    cout << 0 << endl;
    return;
  }

  queue<pair<pair<int, int>, int>> q;  // coords, distance
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  q.push({{0, 0}, 0});
  visited[0][0] = true;

  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    auto coords = p.first;
    int i = coords.first;
    int j = coords.second;
    int distance = p.second;

    // prev
    if (i - 1 >= 0 && !visited[i - 1][j] && g[i - 1][j]) {
      if (x == i - 1 && y == j) {
        cout << distance + 1 << endl;
        return;
      }
      visited[i - 1][j] = true;
      q.push({{i - 1, j}, distance + 1});
    }

    // next
    if (i + 1 < m && !visited[i + 1][j] && g[i + 1][j]) {
      if (x == i + 1 && y == j) {
        cout << distance + 1 << endl;
        return;
      }
      visited[i + 1][j] = true;
      q.push({{i + 1, j}, distance + 1});
    }

    // down
    if (j + 1 < n && !visited[i][j + 1] && g[i][j + 1]) {
      if (x == i && y == j + 1) {
        cout << distance + 1 << endl;
        return;
      }
      visited[i][j + 1] = true;
      q.push({{i, j + 1}, distance + 1});
    }

    // up
    if (j - 1 >= 0 && !visited[i][j - 1] && g[i][j - 1]) {
      if (x == i && y == j - 1) {
        cout << distance + 1 << endl;
        return;
      }
      visited[i][j - 1] = true;
      q.push({{i, j - 1}, distance + 1});
    }
  }

  cout << -1 << endl;
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
