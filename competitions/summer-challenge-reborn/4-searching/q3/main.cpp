#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  vector<int> fib = {1, 1};
  int n;
  cin >> n;
  int size;
  // cout << "Works" << endl;
  while (*(fib.end() - 1) < n) {
    size = fib.size();
    int next = fib[size - 1] + fib[size - 2];
    fib.push_back(next);
  }
  int drops = 0;
  for (int i = fib.size() - 1; i >= 0; --i) {
    drops += n / fib[i];
    n = n % fib[i];
  }
  cout << drops << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    solve();
  }
  return 0;
}
