#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int randomNumber(int l, int r) {
  // * Returns a random integer from [l, r]
  return l + (std::rand() % (r - l + 1));
}

void printVector(const vector<int>& v, string msg) {
  cout << msg;
  for (auto n : v) {
    cout << n << " ";
  }
  cout << endl;
}

// ? Given an array of distinct integers, count all the triplets such that sum
// of two elements equals the third element.

set<vector<int>> naiveApproach(const vector<int>& v) {
  // * T:O(n^3) S:O(n)
  set<vector<int>> res;

  for (int i = 0; i < v.size(); ++i) {
    for (int j = i + 1; j < v.size(); ++j) {
      for (int k = 0; k < v.size(); ++k) {
        if (k == i || k == j) {
          continue;
        }

        if (v[i] + v[j] == v[k]) {
          res.insert({v[i], v[j], v[k]});
        }
      }
    }
  }
  return res;
}

set<vector<int>> hashmapApproach(const vector<int>& v) {
  // * T:O(n^2) S:O(n)
  set<vector<int>> res;

  unordered_map<int, int> hm;  // value => index (Values are distinct)

  for (int i = 0; i < v.size(); ++i) {
    hm[v[i]] = i;
  }

  for (int i = 0; i < v.size(); ++i) {
    for (int j = i + 1; j < v.size(); ++j) {
      if (hm.find(v[i] + v[j]) != hm.end()) {
        // sum exists
        int k = hm[v[i] + v[j]];
        if (k != i && k != j) {
          res.insert({v[i], v[j], v[k]});
        }
      }
    }
  }

  return res;
}

set<vector<int>> twoPointerApproach(vector<int> v) {
  // * T:O(n^2) S:O(1)
  sort(v.begin(), v.end());
  set<vector<int>> res;

  for (int k = v.size() - 1; k >= 0; --k) {
    int l = 0;
    int r = k - 1;
    while (l < r) {
      int sum = v[l] + v[r];
      if (sum == v[k]) {
        res.insert({v[l], v[r], v[k]});
        ++l;
        --r;
      } else if (sum < v[k]) {
        ++l;
      } else {
        --r;
      }
    }
  }

  return res;
}

void smokeTest() {
  for (int i = 0; i < 1000; ++i) {
    cout << "Test Number: " << i << endl;
    // chose random vector
    int n = randomNumber(0, 5);
    vector<int> v;
    unordered_set<int> s;
    for (int j = 0; j < n; ++j) {
      // ensures distinct
      s.insert(randomNumber(0, 1000));
    }
    v = vector<int>(s.begin(), s.end());
    auto a = naiveApproach(v);
    auto b = twoPointerApproach(v);

    if (a != b) {
      cout << "Test failed" << endl;
      printVector(v, "Input: ");
      cout << "Output: " << endl;
      for (auto v : a) {
        printVector(v, "a: ");
      }

      for (auto v : b) {
        printVector(v, "b: ");
      }
      return;
    }
  }
  cout << "Test passed" << endl;
  return;
}

int main(int argc, char const* argv[]) {
  srand(time(0));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  smokeTest();
  return 0;
}
