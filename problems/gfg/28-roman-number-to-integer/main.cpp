#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  string s;
  cin >> s;
  unordered_map<char, int> power;
  power['I'] = 1;
  power['V'] = 5;
  power['X'] = 10;
  power['L'] = 50;
  power['C'] = 100;
  power['D'] = 500;
  power['M'] = 1000;
  int val = 0;
  int currentPower = 'M';
  int i = 0;

  while (i < s.length()) {
    if (s[i] != currentPower) {
      if (i < s.length() - 1 &&
          ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
           (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
           (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')))) {
        val += power[s[i + 1]] - power[s[i]];
        ++i;
      } else {
        // reduction of power
        val += power[s[i]];
        currentPower = s[i];
      }
    } else {
      val += power[currentPower];
    }
    ++i;
  }

  cout << val << endl;
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
