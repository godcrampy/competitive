#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool allowed(int res[], int n) {
  for (int i = 0; i < n; ++i) {
    int l = res[i], r = res[i];
    for (int j = i + 1; j < n; ++j) {
      --l;
      ++r;
      if (res[j] == l || res[j] == r || res[j] == res[i]) return false;
    }
  }

  return true;
}

void nQueens(int i, int n, int res[], bool& solved) {
  // i => need to append at position
  if (i >= n) {
    cout << "[";
    for (int j = 0; j < n; ++j) {
      cout << res[j] + 1 << " ";
    }
    cout << "] ";
    solved = true;
    return;
  }

  for (int j = 0; j < n; ++j) {
    res[i] = j;
    if (allowed(res, i + 1)) nQueens(i + 1, n, res, solved);
  }
}

void solve() {
  int n;
  cin >> n;
  int res[n];
  bool solved = false;
  nQueens(0, n, res, solved);
  if (!solved) cout << -1;

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
