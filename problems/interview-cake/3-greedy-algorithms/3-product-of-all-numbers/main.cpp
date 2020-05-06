#include <iostream>
#include <vector>

using namespace std;

// ! IMP

vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector) {
  // make a vector with the products
  int length = intVector.size();

  if (length <= 1) {
    throw "";
  }
  vector<int> start(length);
  vector<int> end(length);

  start[0] = intVector[0];
  end[length - 1] = intVector[length - 1];

  // fill start
  for (int i = 1; i < length; ++i) {
    start[i] = start[i - 1] * intVector[i];
  }

  // fill end
  for (int i = length - 2; i >= 0; --i) {
    end[i] = end[i + 1] * intVector[i];
  }

  vector<int> res(length);

  for (int i = 1; i < length - 1; ++i) {
    res[i] = start[i - 1] * end[i + 1];
  }

  res[0] = end[1];
  res[length - 1] = start[length - 2];

  return res;
}
