#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  long long n;
  cin >> n;

  vector<int> vals;
  int pos2 = -1;

  while (n > 0) {
    vals.push_back(n % 3);
    if (vals.back() == 2) {
      pos2 = vals.size() - 1;
    }
    n /= 3;
  }

  vals.push_back(0);

  if (pos2 != -1) {
    int pos0 = find(vals.begin() + pos2, vals.end(), 0) - vals.begin();
    vals[pos0] = 1;
    for (int i = pos0 - 1; i >= 0; --i) {
      vals[i] = 0;
    }
  }

  long long ans = 0;
  long long power = 1;
  for (auto i : vals) {
    ans += power * i;
    power *= 3;
  }

  if (vals.back() == 1) ans = power / 3;
  cout << ans << endl;
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
