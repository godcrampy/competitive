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

// ? Given an array of positive integers. Your task is to rearrange  the array
// elements alternatively i.e first element should be max value, second should
// be min value, third should be second max, fourth should be second min and so
// on...

void naiveApproach(vector<int>& v) {
  // * T:O(n^2) S:O(1)
  bool findingMax = true;
  for (int i = 0; i < v.size(); ++i) {
    // index to swap with
    int targetIndex = i;
    for (int j = i; j < v.size(); ++j) {
      if (findingMax) {
        if (v[j] > v[targetIndex]) {
          targetIndex = j;
        }
      } else {
        if (v[j] < v[targetIndex]) {
          targetIndex = j;
        }
      }
    }
    swap(v[i], v[targetIndex]);
    findingMax = !findingMax;
  }
}

void extraArrayApproach(vector<int>& v) {
  // * T:O(n) S:O(n)
  vector<int> sorted = v;
  sort(sorted.begin(), sorted.end());

  int l = 0;
  int r = sorted.size() - 1;

  for (int i = 0; i < sorted.size(); ++i) {
    if (i % 2) {
      // i is odd
      v[i] = sorted[l];
      ++l;
    } else {
      // i is even
      v[i] = sorted[r];
      --r;
    }
  }
}

void dualStorageApproach(vector<int>& v) {
  // * T:O(n) S:O(1)
  // we store 2 values in the same array
  sort(v.begin(), v.end());
  int super = *(v.end() - 1) + 1;  // number greater than the largest element
  int l = 0;
  int r = v.size() - 1;

  for (int i = 0; i < v.size(); ++i) {
    if (i % 2) {
      // i is odd
      // get the max element here
      v[i] += (v[l] % super) * super;
      ++l;
    } else {
      // i is even
      v[i] += (v[r] % super) * super;
      --r;
    }
  }

  // bring back the new values
  // mod gives old values
  // division gives new values
  for (int i = 0; i < v.size(); ++i) {
    v[i] /= super;
  }
}

void smokeTest() {
  for (int i = 0; i < 1000; ++i) {
    cout << "Test " << i + 1 << endl;
    int n = randomNumber(1, 100);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = randomNumber(1, 100);
    }

    vector<int> b = a;
    naiveApproach(a);
    dualStorageApproach(b);

    if (a != b) {
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
  cin.tie(NULL);
  srand(time(0));

  // vector<int> v = {1, 6, 3, 4, 2, 5};
  // extraArrayApproach(v);
  // printVector(v, "rearranged: ");
  smokeTest();
  return 0;
}
