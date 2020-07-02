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

void printVector(const vector<int> &v, string msg) {
  cout << msg;
  for (auto n : v) {
    cout << n << " ";
  }
  cout << endl;
}

// ? Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size
// n and m. The task is to merge the two sorted arrays into one sorted array (in
// non-decreasing order).

int nextGap(int n) { return n <= 1 ? 0 : (n + 1) / 2; }

void swapArrays(vector<int> &a, vector<int> &b, int i, int j) {
  int m = a.size(), n = b.size();
  if (i >= m + n || j >= m + n) {
    // out of bounds
    return;
  }

  if (i >= m) {
    // both in second slot
    if (b[i - m] > b[j - m]) swap(b[i - m], b[j - m]);
  } else {
    // i in first
    if (j >= m) {
      // j in second, i in first
      if (a[i] > b[j - m]) swap(a[i], b[j - m]);
    } else {
      // both in first
      if (a[i] > a[j]) swap(a[i], a[j]);
    }
  }
}

void inplaceMerge(vector<int> &a, vector<int> &b) {
  int m = a.size(), n = b.size();
  int gap = m + n;
  while (gap) {
    for (int i = 0; i < m + n; ++i) {
      swapArrays(a, b, i, i + gap);
    }
    gap = nextGap(gap);
  }
}

void smokeTest() {
  for (int i = 0; i < 100; ++i) {
    cout << "test: " << i + 1 << endl;
    int m = randomNumber(1, 100), n = randomNumber(1, 100);
    vector<int> a(m), b(n);

    for (int j = 0; j < m; ++j) {
      a[j] = randomNumber(1, 100);
    }

    for (int j = 0; j < n; ++j) {
      b[j] = randomNumber(1, 100);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    printVector(a, "a: ");
    printVector(b, "b: ");
    inplaceMerge(a, b);
    auto c = a;
    c.insert(c.end(), b.begin(), b.end());
    printVector(c, "c: ");
    if (!is_sorted(c.begin(), c.end())) {
      cout << "Test failed" << endl;
      return;
    }
  }
  cout << "Test passed" << endl;
}

int main(int argc, char const *argv[]) {
  srand(time(0));

  // vector<int> a = {1, 5, 9, 10, 15, 20}, b = {2, 3, 8, 13};
  // inplaceMerge(a, b);
  // printVector(a, "a: ");
  // printVector(b, "b: ");
  smokeTest();
  return 0;
}
