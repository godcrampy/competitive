#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(long long n) {
  long count = 0;

  while (n != 1) {
    if (n % 6 == 0) {
      n /= 6;
    } else if (n % 3 == 0) {
      n *= 2;
    } else {
      cout << -1 << '\n';
      return;
    }
    ++count;
  }
  cout << count << '\n';
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  long long n;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    solve(n);
  }
  return 0;
}
