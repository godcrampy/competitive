#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> s;
  long score = 0;
  int a;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    s.insert(lower_bound(s.begin(), s.end(), a), a);
    int l = 0;
    int r = s.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (s[m] > a) {
        r = m - 1;
      } else if (s[m] < a) {
        l = m + 1;
      } else {
        r = m;
        break;
      }
    }
    while (r < s.size() && s[r] == a) {
      ++r;
    }
    if (s[r] != a) {
      score += s.size() - r;
    }
  }
  cout << score << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    solve();
  }
  return 0;
}
