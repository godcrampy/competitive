#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> k >> n;
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    if (i < k - 1) {
      cout << -1 << " ";
      q.push(temp);
      continue;
    }

    if (i == k - 1) {
      q.push(temp);
      cout << q.top() << " ";
      continue;
    }

    if (temp < q.top()) {
      cout << q.top() << " ";
    } else {
      q.pop();
      q.push(temp);
      cout << q.top() << " ";
    }
  }

  cout << endl;
}

int main(int argc, char const* argv[]) {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
