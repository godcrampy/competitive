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

void printVector(const vector<int>& v, string msg) {
  cout << msg;
  for (auto n : v) {
    cout << n << " ";
  }
  cout << endl;
}

// ? Given an array arr of N integers. Find the contiguous sub-array with
// maximum sum.

int naiveApproach(const vector<int>& v) {
  // * T:O(n^2) S:O(1)
  if (v.size() == 0) {
    return 0;
  }
  int maxSum = v[0];
  int runningSum = 0;

  for (int i = 0; i < v.size(); ++i) {
    runningSum = 0;
    for (int j = i; j < v.size(); ++j) {
      runningSum += v[j];
      maxSum = max(maxSum, runningSum);
    }
  }

  return maxSum;
}

int kadanesAlgo(const vector<int>& v) {
  // * T:O(n) S:O(n)
  if (v.size() == 0) {
    return 0;
  }

  vector<int> bestEnding(v.size());
  bestEnding[0] = v[0];

  for (int i = 1; i < v.size(); ++i) {
    bestEnding[i] = max(v[i], v[i] + bestEnding[i - 1]);
  }

  return *max_element(bestEnding.begin(), bestEnding.end());
}

void smokeTest() {
  for (int i = 0; i < 100; ++i) {
    cout << "test: " << i << endl;
    int n = randomNumber(1, 1000);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      v[i] = randomNumber(-1000, 1000);
    }

    printVector(v, "vector: ");

    int a = naiveApproach(v);
    int b = kadanesAlgo(v);

    if (a != b) {
      cout << "Test Failed" << endl;
      return;
    }
  }
  cout << "Test Passed" << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(0));

  // cout << kadanesAlgo({1, 2, 3, -2, 5}) << endl;
  smokeTest();
  return 0;
}
