#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(string& s) {
  // get numbers
  int numbers = s.length() / 2 + 1;
  vector<int> v(numbers);
  for (int i = 0; i < s.length(); ++i) {
    if (i % 2 == 0) {
      v[i / 2] = s[i] - '0';
    }
  }
  // 123 sort
  int l = 0, m = 0, r = v.size() - 1;
  while (m <= r) {
    switch (v[m]) {
      case 1:
        swap(v[l++], v[m++]);
        break;
      case 2:
        ++m;
        break;
      case 3:
        swap(v[m], v[r--]);
        break;
    }
  }
  // rebuild string
  for (int i = 0; i < s.length(); ++i) {
    if (i % 2 == 0) {
      s[i] = v[i / 2] + '0';
    }
  }
  cout << s << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string t;
  cin >> t;
  solve(t);
  return 0;
}
