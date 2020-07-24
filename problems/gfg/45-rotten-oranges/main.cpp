#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int minTimeToRot(vector<vector<int>>& g, int i, int j, int timeSoFar) {
  if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j] == 0) {
    return INT_MAX;
  }

  if (g[i][j] == 2) {
    return timeSoFar;
  }

  g[i][j] = 0;

  int a = minTimeToRot(g, i + 1, j, timeSoFar + 1);
  int b = minTimeToRot(g, i - 1, j, timeSoFar + 1);
  int c = minTimeToRot(g, i, j + 1, timeSoFar + 1);
  int d = minTimeToRot(g, i, j - 1, timeSoFar + 1);

  g[i][j] = 1;
  return min(a, min(b, min(c, d)));
}

void solve() {
  int m, n;
  cin >> m >> n;

  vector<vector<int>> g(m, vector<int>(n));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }

  int res = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (g[i][j] == 1) {
        res = max(res, minTimeToRot(g, i, j, 0));
      }
    }
  }

  res = res == INT_MAX ? -1 : res;
  cout << res << endl;
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
