#include <iostream>
#include <vector>

using namespace std;

// ! IMP: Counting Sort

vector<int> sortScores(const vector<int>& unorderedScores,
                       int highestPossibleScore) {
  // sort the scores in O(n) time
  vector<int> counts(highestPossibleScore + 1);

  for (int n : unorderedScores) {
    ++counts[n];
  }

  vector<int> res(unorderedScores.size());

  int j = 0;
  for (int i = counts.size() - 1; i >= 0; --i) {
    int times = counts[i];
    for (int k = 0; k < times; ++k) {
      res[j++] = i;
    }
  }

  return res;
}
