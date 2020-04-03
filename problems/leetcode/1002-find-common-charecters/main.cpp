#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> commonChars(vector<string>& A) {
  if (A.size() == 0) return {};

  vector<map<string, int>> freq(A.size());
  for (int i = 0; i < A.size(); ++i) {
    string s = A[i];
    for (char c : s) {
      string str(1, c);
      ++freq[i][str];
    }
  }

  vector<string> res;

  for (auto p : freq[0]) {
    string i = p.first;
    int min_occ = p.second;
    for (auto m : freq) {
      if (m.find(i) == m.end()) {
        min_occ = 0;
        break;
      }
      min_occ = min(min_occ, m[i]);
    }
    if (min_occ) {
      for (int j = 0; j < min_occ; ++j) {
        res.push_back(i);
      }
    }
  }
  return res;
}