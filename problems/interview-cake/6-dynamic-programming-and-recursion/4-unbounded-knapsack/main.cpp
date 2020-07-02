#include <iostream>
#include <vector>

using namespace std;

// ! IMP

class CakeType {
 public:
  const unsigned int weight_;
  const unsigned int value_;

  CakeType(unsigned int weight = 0, unsigned int value = 0)
      : weight_(weight), value_(value) {}
};

unsigned long long maxDuffelBagValue(const std::vector<CakeType>& cakeTypes,
                                     unsigned int weightCapacity) {
  // calculate the maximum value that we can carry
  vector<int> dp(weightCapacity + 1, 0);

  for (auto cake : cakeTypes) {
    if (cake.weight_ == 0 && cake.value_ != 0) {
      throw "";
    }
    for (unsigned int i = cake.weight_; i < dp.size(); ++i) {
      dp[i] = dp[i] > dp[i - cake.weight_] + cake.value_
                  ? dp[i]
                  : dp[i - cake.weight_] + cake.value_;
    }
  }

  return dp[weightCapacity];
}
