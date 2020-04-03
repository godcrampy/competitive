#include <string>
#include <vector>

using namespace std;

vector<string> wordSubsets(vector<string> &A, vector<string> &B) {
  vector<int> max_index(26, 0);

  for (int i = 0; i < B.size(); ++i) {
    auto vec = get_char_freq(B[i]);

    for (int j = 0; j < 26; ++j) {
      max_index[j] = max(max_index[j], vec[j]);
    }
  }

  vector<string> res;

  for (int i = 0; i < A.size(); ++i) {
    string s = A[i];
    auto vec = get_char_freq(s);
    if (is_greater(vec, max_index)) {
      res.push_back(s);
    }
  }

  return res;
}

vector<int> get_char_freq(string &s) {
  vector<int> ret(26, 0);
  for (char c : s) {
    ret[c - 'a']++;
  }
  return ret;
}

bool is_greater(vector<int> &a, vector<int> &b) {
  for (int i = 0; i < 26; ++i) {
    if (a[i] < b[i]) return false;
  }
  return true;
}