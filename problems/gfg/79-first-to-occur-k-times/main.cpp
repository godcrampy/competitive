#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  unordered_map<int, int> m;
  queue<int> firstK;

  int i;
  while (n--) {
    cin >> i;
    m[i]++;
    firstK.push(i);
  }

  while (!firstK.empty() && m[firstK.front()] != k) {
    firstK.pop();
  }

  if (firstK.empty()) {
    cout << "-1\n";
  } else {
    cout << firstK.front() << endl;
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
