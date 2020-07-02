#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool isUniqueSet(string &s) {
  // * Time: O(nlogn)
  // * Space: O(1) as max insert is 26
  unordered_set<char> t;
  for (char c : s) {
    if (t.find(c) != t.end()) {
      // found
      return false;
    }
    t.insert(c);
  }
  return true;
}

bool isUniqueVector(string &s) {
  // * Time: O(n)
  // * Space: O(1)
  vector<bool> map(128, false);  // assuming ascii
  for (char c : s) {
    if (map[c]) return false;
    map[c] = true;
  }
  return true;
}

bool isUniqueBit(string &s) {
  // * Time: O(n)
  // * Space: O(1) Lesser memory
  int checker = 0;  // assuming only lowercase
  for (char c : s) {
    if (checker & (1 << (c - 'a'))) return false;
    checker |= 1 << (c - 'a');
  }
  return true;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    cout << isUniqueSet(s) << " " << isUniqueVector(s) << " " << isUniqueBit(s)
         << endl;
  }
  // * Other possible solutions
  // * Brute Force: Time => O(n^2), Space => O(1)
  // * Sort: Time => O(nlogn), Space => O(1)
  return 0;
}
