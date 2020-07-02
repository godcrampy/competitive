#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long getCount(const string& s, int i) {
  long long l = i;
  long long r = s.length() - i - 1;
  return (l + 1) * (r + 1);
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long count = 0;
  for (int i = 0; i < s.length(); ++i) {
    char c = s[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
        c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      count += getCount(s, i);
    }
  }
  cout << count << endl;
}

int main(int argc, char const* argv[]) {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    solve();
  }
  return 0;
}
