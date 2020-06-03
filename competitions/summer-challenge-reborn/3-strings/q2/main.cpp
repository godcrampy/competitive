#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  string s;
  cin >> s;
  bool slashFound = false;
  bool letterFound = false;
  vector<string> store;
  int l = -1;
  int r = 0;

  int i = 0;
  while (i < s.length()) {
    char c = s[i];
    if (c == '/') {
      // check if next slash exists
      if (i + 1 < s.length() && s[i + 1] == '/') {
        i += 2;
        // skip till you find another slash
        while (i < s.length() && s[i] != '/') {
          ++i;
        }
      } else {
        // add previous string
        if (l != -1) {
          store.push_back(s.substr(l, r));
        }
      }
    } else {
      // letter found
      l = i;
      r = 0;
      while (i < s.length() && s[i] != '/') {
        ++i;
        ++r;
      }
      --i;
    }
    i++;
  }

  cout << store.size() << endl;
  for (string s : store) {
    cout << s << endl;
  }
}

int main(int argc, char const* argv[]) {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    solve();
  }
  return 0;
}
