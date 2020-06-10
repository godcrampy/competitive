#include <limits.h>

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int randomNumber(int l, int r) {
  // * Returns a random integer from [l, r]
  srand(time(0));
  return l + (std::rand() % (r - l + 1));
}

// ? Subarray with given sum
// * Given an unsorted array of integers, find a continuous subarray which adds to a given number.

pair<int, int> naiveApproach(const vector<int>& v, int sum) {
  // * T:O(n^2) S:O(1)

  if (v.size() == 0) {
    cout << -1 << endl;
    return {-1, -1};
  }

  for (int i = 0; i < v.size(); ++i) {
    int s = 0;
    for (int j = i; j < v.size(); ++j) {
      s += v[j];
      if (s == sum) {
        // cout << i << " " << j << endl;
        return {i, j};
      }
    }
  }
  // cout << -1 << endl;
  return {-1, -1};
}

pair<int, int> twoPointerApproach(const vector<int>& v, int sum) {
  // * T:O(n) S:O(1)
  // ? Only works with positive elements in v

  if (v.size() == 0) {
    cout << -1 << endl;
    return {-1, -1};
  }
  int l = 0;
  int s = 0;
  for (int r = 0; r < v.size(); ++r) {
    s += v[r];
    while (s > sum && l < v.size()) {
      s -= v[l];
      ++l;
    }

    if (sum == s) {
      // cout << l << " " << r << endl;
      return {l, r};
    }
  }

  // cout << -1 << endl;
  return {-1, -1};
}

pair<int, int> hashmapApproach(const vector<int>& v, int sum) {
  // * T:O(n) S:O(n)

  if (v.size() == 0) {
    return {-1, -1};
  }

  unordered_map<int, int> hm;  // prefix sum => index
  int s = 0;
  for (int r = 0; r < v.size(); ++r) {
    s += v[r];
    hm[s] = r;
    if (s == sum) {
      return {0, r};
    }

    if (hm.find(s - sum) != hm.end()) {
      // window exists
      return {hm[s - sum], r};
    }
  }
  return {-1, -1};
}

void smokeTest() {
  for (int i = 0; i < 10000; ++i) {
    // chose vector size
    int n = randomNumber(0, 1000);
    int sum = randomNumber(0, 1000);
    vector<int> v(n);
    for (int j = 0; j < n; ++j) {
      v[j] = randomNumber(0, 1000);
    }

    auto a = naiveApproach(v, sum);
    auto b = hashmapApproach(v, sum);
    if (a != b) {
      cout << "Test failed" << endl;
      return;
    }
  }
  cout << "Test passed" << endl;
  return;
}

int main(int argc, char const* argv[]) {
  smokeTest();
  return 0;
}
