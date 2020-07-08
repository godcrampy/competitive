#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  string s;
  cin >> s;

  vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));

  for (int i = 0; i < s.length(); ++i) {
    dp[i][i] = true;
  }
  int maxLength = 1;

  for (int i = 0; i < s.length() - 1; ++i) {
    if (s[i] == s[i + 1]) {
      dp[i][i + 1] = true;
      maxLength = 2;
    }
  }

  for (int k = 3; k <= s.length(); ++k) {
    for (int i = 0; i + k - 1 < s.length(); ++i) {
      int j = i + k - 1;
      if (dp[i + 1][j - 1] && s[i] == s[j]) {
        dp[i][j] = true;
        if (k > maxLength) {
          maxLength = k;
        }
      }
    }
  }

  for (int i = 0; i + maxLength - 1 < s.length(); ++i) {
    int j = i + maxLength - 1;
    if (dp[i][j]) {
      cout << s.substr(i, maxLength) << endl;
      return;
    }
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
