#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_map>
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

// ? Given two arrays X and Y of positive integers, find number of pairs such
// that x^y > y^x (raised to power of) where x is an element from X and y is an
// element from Y.

long naiveApproach(const vector<int> x, const vector<int> y) {
  // * T:O(mn) S:O(1)
  long pairs = 0;
  for (int X : x) {
    for (int Y : y) pairs += pow(X, Y) > pow(Y, X);
  }
  return pairs;
}

long sortApproach(const vector<int>& x, vector<int>& y) {
  // * T:O(nlogn + mlogm) S:O(1)
  unordered_map<int, int> freq;  // value => frequency
  for (int i : y) {
    if (i < 5) {
      ++freq[i];
    }
  }

  sort(y.begin(), y.end());

  long pairs = 0;

  for (auto i : x) {
    if (i == 0)
      continue;
    else if (i == 1) {
      pairs += freq[0];
    } else {
      auto idx = upper_bound(y.begin(), y.end(), i);
      pairs += y.end() - idx + freq[0] + freq[1];

      // Special cases
      if (i == 2) pairs -= freq[3] + freq[4];
      if (i == 3) pairs += freq[2];
    }
  }

  return pairs;
}

void smokeTest() {
  for (int i = 0; i < 1000; ++i) {
    cout << "Test " << i + 1 << endl;
    int n = randomNumber(1, 100), m = randomNumber(1, 100);

    vector<int> x(m), y(n);
    for (int i = 0; i < m; ++i) {
      x[i] = randomNumber(1, 100);
    }

    for (int i = 0; i < n; ++i) {
      y[i] = randomNumber(1, 100);
    }

    long a = naiveApproach(x, y);
    long b = sortApproach(x, y);

    if (a != b) {
      cout << "Test failed" << endl;
      printVector(x, "a: ");
      printVector(y, "b: ");
      return;
    }
  }
  cout << "Test passed" << endl;
}

int main(int argc, char const* argv[]) {
  srand(time(0));

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  smokeTest();
  return 0;
}
