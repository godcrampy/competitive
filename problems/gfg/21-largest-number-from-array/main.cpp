#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(const string& a, const string& b) {
  string ab = a + b;
  string ba = b + a;

  return ab > ba;
}

void solve() {
  int n;
  cin >> n;
  vector<string> v(n);

  int temp;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    v[i] = to_string(temp);
  }

  sort(v.begin(), v.end(), compare);

  for (auto s : v) {
    cout << s;
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
