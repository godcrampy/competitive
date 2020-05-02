#include <limits.h>

#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeVectors(const vector<int>& myVector, const vector<int>& alicesVector) {
  // combine the sorted vectors into one large sorted vector
  int l1 = myVector.size();
  int l2 = alicesVector.size();
  vector<int> final(l1 + l2);
  int i1 = 0;
  int i2 = 0;
  int i = 0;
  while (i1 < l1 || i2 < l2) {
    int v1 = i1 < l1 ? myVector[i1] : INT_MAX;
    int v2 = i2 < l2 ? alicesVector[i2] : INT_MAX;

    if (v1 < v2) {
      final[i++] = v1;
      ++i1;
    } else {
      final[i++] = v2;
      ++i2;
    }
  }

  return final;
}