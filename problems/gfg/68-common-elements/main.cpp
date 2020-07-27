#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve() {
  long n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  vector<long long> v1(n1), v2(n2), v3(n3);

  for (long i = 0; i < n1; ++i) {
    cin >> v1[i];
  }

  for (long i = 0; i < n2; ++i) {
    cin >> v2[i];
  }

  for (long i = 0; i < n3; ++i) {
    cin >> v3[i];
  }

  long i1 = 0, i2 = 0, i3 = 0;
  set<long long> s;

  while (i1 < n1 && i2 < n2 && i3 < n3) {
    long long next = max(v1[i1], max(v2[i2], v3[i3]));

    while (i1 < n1 && v1[i1] < next) {
      ++i1;
    }

    while (i2 < n2 && v2[i2] < next) {
      ++i2;
    }

    while (i3 < n3 && v3[i3] < next) {
      ++i3;
    }

    if (i1 < n1 && i2 < n2 && i3 < n3 && v1[i1] == next && v2[i2] == next &&
        v3[i3] == next) {
      s.insert(next);
      ++i1;
      ++i2;
      ++i3;
    }
  }

  if (s.size() == 0) {
    cout << -1 << endl;
    return;
  }
  for (auto i : s) {
    cout << i << " ";
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
