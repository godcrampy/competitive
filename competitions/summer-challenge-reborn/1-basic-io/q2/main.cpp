#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  long long count = 0;
  for (int i = 0; i < n; ++i) {
    if (c[i] < a[i] + b[i]) {
      count += a[i] + b[i] - c[i];
    }
  }

  cout << count << endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    solve();
  }
  return 0;
}
