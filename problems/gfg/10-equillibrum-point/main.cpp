#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int randomNumber(int l, int r) {
  // * Returns a random integer from [l, r]
  return l + (std::rand() % (r - l + 1));
}

template <typename T>
void printVector(const vector<T>& v, string msg) {
  cout << msg;
  for (auto n : v) {
    cout << n << " ";
  }
  cout << endl;
}

// ? Given an array A of N positive numbers. The task is to find the position
// where equilibrium first occurs in the array. Equilibrium position in an array
// is a position such that the sum of elements before it is equal to the sum of
// elements after it.

int naiveApproach(const vector<int>& v) {
  // * T:O(n^2) S:O(1)
  for (int i = 0; i < v.size(); ++i) {
    long left = 0;
    long right = 0;

    for (int j = 0; j < i; ++j) {
      left += v[j];
    }

    for (int j = i + 1; j < v.size(); ++j) {
      right += v[j];
    }

    if (left == right) {
      return i;
    }
  }
  return -1;
}

int sumApproach(const vector<int>& v) {
  // * T:O(n) S:O(1)
  long sum = 0;
  for (auto i : v) {
    sum += i;
  }

  long l = 0;
  long r = sum - v[0];
  int i = 0;
  while (l < r && i < v.size()) {
    l += v[i];
    r -= v[i + 1];
    ++i;
  }

  if (l == r) {
    return i;
  }
  return -1;
}

void smokeTest() {
  for (int i = 0; i < 1000; ++i) {
    cout << "Test: " << i + 1 << endl;
    int n = randomNumber(1, 1000);
    vector<int> v(n);
    for (int j = 0; j < n; ++j) {
      v[j] = randomNumber(1, 1000);
    }
    int a = naiveApproach(v);
    int b = sumApproach(v);
    if (a != b) {
      cout << "Test Failed" << endl;
      vector<int> ans = {a, b};
      printVector(ans, "a, b: ");
      return;
    }
  }
  cout << "Test Passed" << endl;
}

int main(int argc, char const* argv[]) {
  srand(time(0));

  smokeTest();
  return 0;
}
