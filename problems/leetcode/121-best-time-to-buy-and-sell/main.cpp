#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
  if (prices.size() == 0) return 0;
  vector<int> max_profit(prices.size(), prices[prices.size() - 1]);

  for (int i = prices.size() - 2; i >= 0; --i) {
    max_profit[i] = max(max_profit[i + 1], prices[i]);
  }

  int res = 0;

  for (int i = 0; i < prices.size(); ++i) {
    res = max(res, max_profit[i] - prices[i]);
  }
  return res;
}