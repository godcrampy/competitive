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

// ? Given an array A of size N containing 0s, 1s, and 2s; you need to sort the
// array in ascending order.

void naiveApproach(vector<int>& v) {
  // * T:O(nlogn) S:O(1)
  sort(v.begin(), v.end());
}

void counterApproach(vector<int>& v) {
  // * T:O(n) S:O(1) [Two Passes]
  int zero = 0, one = 0, two = 0;

  for (int n : v) {
    switch (n) {
      case 0:
        ++zero;
        break;
      case 1:
        ++one;
        break;
      case 2:
        ++two;
        break;
      default:
        break;
    }
  }

  auto i = 0;
  while (zero--) {
    v[i++] = 0;
  }
  while (one--) {
    v[i++] = 1;
  }
  while (two--) {
    v[i++] = 2;
  }
}

void threePointerApproach(vector<int>& v) {
  // * T:O(n) S:O(1) [One Passes]
  int l = 0, m = 0, r = v.size() - 1;

  while (m <= r) {
    switch (v[m]) {
      case 0:
        swap(v[l++], v[m++]);
        break;

      case 1:
        ++m;
        break;

      case 2:
        swap(v[m], v[r--]);
        break;

      default:
        break;
    }
  }
}

void smokeTest() {
  for (int i = 0; i < 1000; ++i) {
    cout << "Test " << i + 1 << endl;
    int n = randomNumber(1, 1000);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = randomNumber(0, 2);
    }

    vector<int> b = a;
    naiveApproach(a);
    threePointerApproach(b);

    if (a != b || !is_sorted(a.begin(), a.end())) {
      cout << "Test failed" << endl;
      printVector(a, "a: ");
      printVector(b, "b: ");
      return;
    }
  }
  cout << "Test passed" << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  srand(time(0));
  smokeTest();
  cin.tie(NULL);
  return 0;
}
