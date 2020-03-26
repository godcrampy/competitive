#include <set>
#include <string>

using namespace std;

// * Good Problem

int lengthOfLongestSubstring(string s) {
  int max_length = 0;
  int i = 0;
  int j = 0;

  set<char> c;

  while (j < s.length()) {
    if (c.find(s[j]) == c.end()) {
      // not found
      c.insert(s[j]);
      max_length = max_length > c.size() ? max_length : c.size();
      ++j;
    } else {
      // found => move i by one
      c.erase(s[i]);
      ++i;
    }
  }
  return max_length;
}