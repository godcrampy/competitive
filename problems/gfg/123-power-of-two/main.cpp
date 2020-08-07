#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  long long n;
  cin >> n;
  if (!(n & (n - 1)) && (n)) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
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
