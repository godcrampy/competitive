#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(int t) {
  int count = 0;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c >= 2) {
      ++count;
    }
  }
  cout << count << '\n';
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  solve(t);
  return 0;
}
