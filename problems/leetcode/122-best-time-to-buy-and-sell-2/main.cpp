#include <vector>

using namespace std;

bool isPeak(const vector<int>& prices, int position) {
  int n = prices.size();
  if (n == 1) {
    return true;
  }
  if (position == n - 1) {
    return prices[position] > prices[position - 1];
  }
  if (position == 0) {
    return prices[position] > prices[position + 1];
  }

  return (prices[position] >= prices[position - 1]) &&
         (prices[position] >= prices[position + 1]);
}

bool isValley(const vector<int>& prices, int position) {
  int n = prices.size();
  if (n == 1) {
    return true;
  }
  if (position == n - 1) {
    return prices[position] < prices[position - 1];
  }
  if (position == 0) {
    return prices[position] < prices[position + 1];
  }

  return (prices[position] <= prices[position - 1]) &&
         (prices[position] < prices[position + 1]);
}

int maxProfit(vector<int>& prices) {
  int profit = 0;
  bool haveBought = false;
  int buyingPrice;
  for (int i = 0; i < prices.size(); ++i) {
    if (haveBought) {
      if (isPeak(prices, i)) {
        // sell it
        haveBought = false;
        profit += prices[i] - buyingPrice;
      }
    } else {
      if (isValley(prices, i)) {
        // buy it
        haveBought = true;
        buyingPrice = prices[i];
      }
    }
  }

  return profit;
}