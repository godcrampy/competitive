#include <limits.h>

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

// ? Given an array of positive integers. The task is to find inversion count of array. Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

long naiveApproach(vector<long long>& v) {
  // * T:O(n^2) S:O(1)
  long count = 0;
  for (int i = 0; i < v.size(); ++i) {
    for (int j = i + 1; j < v.size(); ++j) {
      if (v[j] < v[i]) {
        ++count;
      }
    }
  }
  return count;
}

long mergeSortApproach(vector<long long>& v, int l, int r) {
  // * T:O(nlogn) S:O(n)
  if (l >= r) {
    return 0;
  }

  int m = l + (r - l) / 2;
  long count = mergeSortApproach(v, l, m);
  count += mergeSortApproach(v, m + 1, r);

  // merge
  vector<long long> temp(v.begin() + l, v.begin() + r + 1);

  int x = l;
  int y = m + 1;
  int z = l;
  while (x <= m || y <= r) {
    long long a = x <= m ? temp[x - l] : LONG_LONG_MAX;
    long long b = y <= r ? temp[y - l] : LONG_LONG_MAX;

    if (a > b) {
      v[z++] = temp[y++ - l];
      count += m - x + 1;
    } else {
      v[z++] = temp[x++ - l];
    }
  }
  return count;
}

long mergeSortApproach(vector<long long>& v) {
  return mergeSortApproach(v, 0, v.size() - 1);
}

void smokeTest() {
  for (int i = 0; i < 1000; ++i) {
    cout << "Test " << i + 1 << endl;
    int n = randomNumber(1, 100);

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = randomNumber(1, 100);
    }

    vector<long long> b = a;
    long x = naiveApproach(a);
    long y = mergeSortApproach(b);

    if (x != y) {
      cout << "Test failed" << endl;
      printVector(a, "a: ");
      printVector(b, "b: ");
      return;
    }
  }
  cout << "Test passed" << endl;
}

void solve() {
  long n;
  cin >> n;
  vector<long long> v(n);
  for (long i = 0; i < n; ++i) {
    cin >> v[i];
  }

  cout << naiveApproach(v) << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(0));
  smokeTest();
  return 0;
}
