#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  string s, p;
  cin >> s >> p;
  unordered_map<char, int> patternMap, strMap;

  for (char c : p) {
    patternMap[c]++;
  }

  int count = 0;

  int startIndex = 0, minLen = INT_MAX, minStart = -1;

  for (int i = 0; i < s.length(); ++i) {
    strMap[s[i]]++;

    if (patternMap.find(s[i]) != patternMap.end() &&
        strMap[s[i]] <= patternMap[s[i]]) {
      ++count;
    }

    if (count == p.length()) {
      // try to minimize
      while (patternMap.find(s[startIndex]) == patternMap.end() ||
             strMap[s[startIndex]] > patternMap[s[startIndex]]) {
        if (patternMap.find(s[startIndex]) != patternMap.end()) {
          --strMap[s[startIndex]];
        }
        ++startIndex;
      }

      int len = i - startIndex + 1;

      if (len < minLen) {
        minLen = len;
        minStart = startIndex;
      }
    }
  }

  if (minStart == -1) {
    cout << "-1\n";
  } else {
    cout << s.substr(minStart, minLen) << endl;
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
