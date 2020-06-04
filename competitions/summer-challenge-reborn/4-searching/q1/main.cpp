#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> scores(n);
  for (int i = 0; i < n; ++i) {
    cin >> scores[i];
  }

  sort(scores.begin(), scores.end());
  if (n >= m) {
    cout << 1 << endl;
    return;
  }

  long iterations = 1;
  while (m > 0) {
    for (int i : scores) {
      if (iterations % i == 0) {
        --m;
        if (m == 0) {
          break;
        }
      }
    }
    ++iterations;
  }

  cout << iterations - 1 << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
