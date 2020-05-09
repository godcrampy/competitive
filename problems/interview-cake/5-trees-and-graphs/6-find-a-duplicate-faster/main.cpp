#include <iostream>
#include <vector>

using namespace std;

// ! IMP

unsigned int findDuplicate(const vector<unsigned int>& intVector) {
  // find a number that appears more than once ... in O(n) time
  int n = intVector.size() - 1;

  int itr1 = n + 1;

  for (int i = 0; i < n + 1; ++i) {
    itr1 = intVector[itr1 - 1];
  }

  // itr1 is in the loop
  // find length
  int length = 1;
  int saveItr = itr1;

  itr1 = intVector[itr1 - 1];

  while (itr1 != saveItr) {
    itr1 = intVector[itr1 - 1];
    ++length;
  }

  // set itr1 to the start of head
  itr1 = n + 1;

  for (int i = 0; i < length; ++i) {
    itr1 = intVector[itr1 - 1];
  }

  int itr2 = n + 1;

  while (itr2 != itr1) {
    itr1 = intVector[itr1 - 1];
    itr2 = intVector[itr2 - 1];
  }

  // itr1 is on repeated index

  return itr1;
}
