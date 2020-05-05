#include <limits.h>

#include <iostream>
#include <vector>

using namespace std;

// ! IMP

int getMaxProfit(const vector<int>& stockPrices) {
  // calculate the max profit
  int length = stockPrices.size();

  if (length < 2) {
    throw "";
  }
  int minSoFar = stockPrices[0];
  int maxProfit = stockPrices[1] - stockPrices[0];
  for (int i = 1; i < length; ++i) {
    int n = stockPrices[i];
    if (n < minSoFar) {
      minSoFar = n;
    } else {
      maxProfit = max(maxProfit, n - minSoFar);
    }
  }

  return maxProfit;
}
