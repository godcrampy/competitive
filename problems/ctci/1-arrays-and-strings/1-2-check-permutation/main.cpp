#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool checkPermutationMap(string &a, string &b) {
  // * Time: O(|a| + |b|)
  // * Space: O(1) as max size is 128
  unordered_map<char, int> ma, mb;
  for (auto c : a) {
    ++ma[c];
  }
  for (auto c : b) {
    ++mb[c];
  }
  if (ma.size() != mb.size()) return false;

  for (auto p : ma) {
    if (p.second != mb[p.first]) return false;
  }
  return true;
}

bool checkPermutationSort(string a, string b) {
  // * Time: O(|a|log|a| + |b|log|b|)
  // * Space: O(1)
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (a.length() != b.length()) return false;

  for (int i = 0; i < a.length(); ++i) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    cout << checkPermutationMap(a, b) << " " << checkPermutationSort(a, b)
         << endl;
  }
  return 0;
}
