#include <limits.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

long lSBP(long long n) {
  return (long)(log2(n));
}

bool isKthBitSet(long long n, long k) {
  if ((n >> (k)) & 1)
    return true;
  return false;
}

void solve() {
  // std::cout << "Solbinf...." << endl;
  long long n;
  long m;
  cin >> n >> m;
  vector<long long> nums(m);

  for (long i = 0; i < m; ++i) {
    cin >> nums[i];
  }

  unordered_map<long, long> store;  // power -> freq
  for (long long i : nums) {
    store[lSBP(i)]++;
  }

  long count = 0;
  for (long p = 63; p >= 0; --p) {
    if (isKthBitSet(n, p)) {
      // std::cout << "p: " << p << endl;
      long times = 1;
      long i = p - 1;
      bool more = true;
      if (store.find(p) != store.end() && store[p] >= 1) {
        store[p]--;
        if (store[p] == 0) {
          store.erase(p);
        }
        continue;
      }
      // we couldn't find at p

      // find below
      long long target = (1 << p);
      auto tempStore = store;
      bool found = false;
      while (target > 0 && i >= 0) {
        // cout << "i: " << i << endl;
        long timesRequired = target / (1 << i);
        long timesHave = tempStore[i];
        long timesWellTake = min(timesHave, timesRequired);
        // cout << "timesRequired: " << timesRequired << endl;
        // cout << "timesHave: " << timesHave << endl;
        // cout << "timesWellTake: " << timesWellTake << endl;
        tempStore[i] -= timesWellTake;
        if (tempStore[i] == 0) {
          tempStore.erase(i);
        }
        target -= (timesWellTake) * (1 << i);
        --i;
        // cout << "target: " << target << endl;
        if (target == 0) {
          found = true;
        }
      }

      if (found) {
        store = tempStore;
        continue;
      }

      // while (i >= 0) {
      //   if (store[i] >= times) {
      //     store[i] -= times;
      //     if (store[i] == 0) {
      //       store.erase(i);
      //     }
      //     more = false;
      //     break;
      //   }
      //   if (store[i] == 0) {
      //     store.erase(i);
      //   }
      //   times *= 2;
      //   --i;
      // }

      // std::cout << "more" << endl;
      long biggerThanP = INT_MAX;
      found = false;
      for (auto pr : store) {
        if (pr.first > p) {
          biggerThanP = min(biggerThanP, pr.first);
          // cout << "Bigger than p: " << biggerThanP << endl;
          found = true;
        }
      }
      if (!found) {
        // not possible
        std::cout << -1 << endl;
        return;
      }

      long next = biggerThanP;
      // std::cout << "next: " << next << endl;
      store[next]--;
      while (next != p) {
        --next;
        store[next]++;
        ++count;
      }
      // for (auto p : store) {
      //   std::cout << p.first << ": " << p.second << endl;
      // }
    }
  }

  std::cout << count << endl;
}

int main(long argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long t;
  cin >> t;
  for (long i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
