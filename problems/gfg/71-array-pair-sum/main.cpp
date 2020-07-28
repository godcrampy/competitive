#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  cin >> k;

  unordered_map<int, deque<int>> m;
  sort(v.begin(), v.end());

  for (int i = 0; i < n; ++i) {
    m[v[i] % k].push_back(i);
  }

  vector<bool> foundPair(n, false);

  for (int i = 0; i < n; ++i) {
    if (!foundPair[i]) {
      int rem = v[i] % k;
      m[rem].pop_front();
      int compliment = (k - rem) % k;
      if (m[compliment].empty()) {
        cout << "False" << endl;
        return;
      }
      int complimentIndex = m[compliment].front();
      m[compliment].pop_front();
      foundPair[i] = true;
      foundPair[complimentIndex] = true;
    }
  }

  cout << "True" << endl;
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
