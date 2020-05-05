#include <iostream>
#include <vector>

using namespace std;

bool isFirstComeFirstServed(const vector<int>& takeOutOrders,
                            const vector<int>& dineInOrders,
                            const vector<int>& servedOrders) {
  // check if we're serving orders first-come, first-served
  int i1 = 0;
  int l1 = takeOutOrders.size();
  int i2 = 0;
  int l2 = dineInOrders.size();
  if (l1 + l2 != servedOrders.size()) return false;

  for (int n : servedOrders) {
    if (i1 < l1 && n == takeOutOrders[i1]) {
      ++i1;
      continue;
    }
    if (i2 < l2 && n == dineInOrders[i2]) {
      ++i2;
      continue;
    }
    return false;
  }
  return true;
}