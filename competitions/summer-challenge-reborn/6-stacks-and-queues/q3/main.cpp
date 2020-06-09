#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>

using namespace std;

void solve() {
  string s;
  cin >> s;
  list<char> ans, p;
  multiset<char> m;  // alphabet => frequency
  for (char c : s) {
    m.insert(c);
  }

  for (char c : s) {
    if (*m.begin() == c && (p.empty() || c < p.back())) {
      ans.push_back(c);
      m.erase(m.begin());
    } else {
      // * check if there are smaller ones inside
      while (!p.empty() && p.back() <= c && p.back() <= *m.begin()) {
        // add to ans
        ans.push_back(p.back());
        // m.erase(m.find(p.back()));
        p.pop_back();
      }
      p.push_back(c);
      m.erase(m.find(c));
    }
  }

  p.reverse();
  ans.splice(ans.end(), p);
  for (char c : ans) {
    cout << c;
  }
  cout << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
