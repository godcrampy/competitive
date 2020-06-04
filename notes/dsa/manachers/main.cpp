#include <iostream>
#include <string>
#include <vector>

using namespace std;

// * Finds the longest length palindrome in linear time

long maxLengthPalindrome(const string& str) {
  int n = str.length();
  if (n == 0) return 0;

  n = 2 * n + 1;
  vector<int> LPS(n);
  LPS[0] = 0;
  LPS[1] = 1;
  int c = 1;  // current position
  int r = 1;  // center right
  int iMirror;
  bool expand = false;
  int diff = -1;
  int maxLPSLength = 0;
  int maxLPSCenterPosition = 0;
  int start = -1;
  int end = -1;

  for (int i = 2; i < n; ++i) {
    // i = current right position
    iMirror = 2 * c - i;

    expand = false;
    diff = r - i;

    if (diff >= 0) {
      if (LPS[iMirror] < diff) {
        // Case 1
        LPS[i] = LPS[iMirror];
      } else if (LPS[iMirror] == diff && r == n - 1) {
        // Case 2
        LPS[i] = LPS[iMirror];
      } else if (LPS[iMirror] == diff && r < n - 1) {
        // Case 3
        LPS[i] = LPS[iMirror];
        expand = true;  // expansion required
      } else if (LPS[iMirror] > diff) {
        // Case 4
        LPS[i] = diff;
        expand = true;  // expansion required
      }
    } else {
      LPS[i] = 0;
      expand = true;
    }

    if (expand) {
      // Do expansion
      while (((i + LPS[i]) < n && (i - LPS[i]) > 0) &&
             (((i + LPS[i] + 1) % 2 == 0) ||
              (str[(i + LPS[i] + 1) / 2] == str[(i - LPS[i] - 1) / 2]))) {
        ++LPS[i];
      }
    }

    if (LPS[i] > maxLPSLength) {
      maxLPSLength = LPS[i];
      maxLPSCenterPosition = i;
    }

    // If palindrome centered at currentRightPosition i
    // expand beyond centerRightPosition R,
    // adjust centerPosition C based on expanded palindrome.
    if (i + LPS[i] > r) {
      c = i;
      r = i + LPS[i];
    }
  }

  return maxLPSLength;
}

int main(int argc, char const* argv[]) {
  string s;
  cin >> s;
  cout << maxLengthPalindrome(s) << endl;
  return 0;
}
