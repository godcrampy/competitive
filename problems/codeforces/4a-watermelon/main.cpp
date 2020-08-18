#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(int n) {
  if (n != 2 && n % 2 == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  solve(n);
  return 0;
}
