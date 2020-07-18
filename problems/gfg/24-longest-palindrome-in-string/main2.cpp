#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string longestPalindromeSubstring(const string& s) {
  int n = s.length();
  n = 2 * n + 1;
  vector<int> lps(n);

  int C = 1, R = 2, i = 0, iMirror, diff;
  int maxLPSLength = 0;
  int maxLPSCenterPosition = 0;
  bool expand = false;
  lps[0] = 0;
  lps[1] = 1;

  for (i = 0; i < n; ++i) {
    iMirror = 2 * C - i;
    diff = R - i;
    expand = false;

    if (diff >= 0) {
      if (lps[iMirror] < diff) {
        // case 1
        lps[i] = lps[iMirror];
      } else if (lps[iMirror] == diff && R == n - 1) {
        // case 2
        lps[i] = lps[iMirror];
      } else if (lps[iMirror] == diff && R < n - 1) {
        lps[i] = lps[iMirror];
        expand = true;
      } else if (lps[iMirror] > diff) {
        lps[i] = diff;
        expand = true;
      }
    } else {
      lps[i] = 0;
      expand = true;
    }

    if (expand) {
      while (((i + lps[i]) < n && (i - lps[i]) > 0) &&
             (((i + lps[i] + 1) % 2 == 0) ||
              (s[(i + lps[i] + 1) / 2] == s[(i - lps[i] - 1) / 2]))) {
        ++lps[i];
      }
    }

    if (lps[i] > maxLPSLength) {
      maxLPSLength = lps[i];
      maxLPSCenterPosition = i;
    }

    if (i + lps[i] > R) {
      C = i;
      R = i + lps[i];
    }
  }

  int start = (maxLPSCenterPosition - maxLPSLength) / 2;
  return s.substr(start, maxLPSLength);
}

void solve() {
  string s;
  cin >> s;
  cout << longestPalindromeSubstring(s) << endl;
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
