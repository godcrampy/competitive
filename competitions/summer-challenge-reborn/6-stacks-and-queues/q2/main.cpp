#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void solve() {
  string s;
  cin >> s;
  if (s == "") {
    cout << "No" << endl;
    return;
  }
  stack<char> stk;
  int onesInside = 0;
  int oneBelow = false;
  for (char c : s) {
    if (oneBelow) {
      if (c == '}') {
        // * Remove 1
        if (stk.empty()) {
          cout << "No" << endl;
          return;
        }
        stk.pop();
        // * Remove {
        if (stk.empty()) {
          cout << "No" << endl;
          return;
        }
        stk.pop();
        --onesInside;
        oneBelow = onesInside && !stk.empty() && stk.top() == '1';
      } else if (c == '{') {
        stk.push(c);
        ++onesInside;
        oneBelow = false;
      } else {
        cout << "No" << endl;
        return;
      }
    } else {
      if (c == '{') {
        stk.push(c);
      } else if (c == '1') {
        onesInside++;
        oneBelow = true;
        stk.push(c);
      } else {
        cout << "No" << endl;
        return;
      }
    }
  }

  if (stk.empty()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
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
