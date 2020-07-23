#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  deque<char> q;
  vector<int> v(26, 0);
  while (n-- != 0) {
    char i;
    cin >> i;
    v[i - 'a']++;
    q.push_back(i);

    while (!q.empty() && v[q.front() - 'a'] != 1) {
      q.pop_front();
    }

    if (q.empty()) {
      cout << -1 << " ";
    } else {
      cout << q.front() << " ";
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
