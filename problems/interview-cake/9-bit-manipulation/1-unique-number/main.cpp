#include <iostream>
#include <vector>

using namespace std;

// ! IMP

int findUniqueDeliveryId(const vector<int>& deliveryIds) {
  // find the one unique ID in the vector
  int res = 0;

  for (int n : deliveryIds) {
    res ^= n;
  }

  return res;
}
