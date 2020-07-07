#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> mat(m, vector<int>(n));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  int u = 0, d = m, l = 0, r = n;

  while (u < d && l < r) {
    for (int i = l; i < r; ++i) {
      cout << mat[u][i] << " ";
    }
    ++u;

    for (int i = u; i < d; ++i) {
      cout << mat[i][r - 1] << " ";
    }
    --r;

    if (u < d) {
      for (int i = r - 1; i >= l; --i) {
        cout << mat[d - 1][i] << " ";
      }
      --d;
    }

    if (l < r) {
      for (int i = d - 1; i >= u; --i) {
        cout << mat[i][l] << " ";
      }
      ++l;
    }
  }
  cout << endl;
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
