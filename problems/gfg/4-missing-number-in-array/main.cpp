#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
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

// ? Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.

int naiveApproach(const vector<int> v) {
  // * T: O(n^2) S: O(1)
  int n = v.size() + 1;
  for (int i = 1; i <= n; ++i) {
    bool found = false;
    for (auto n : v) {
      if (n == i) {
        found = true;
        break;
      }
    }
    if (!found) {
      return i;
    }
  }
  return -1;
}

int setApproach(const vector<int> v) {
  // * T:O(n) S:O(n)
  int n = v.size() + 1;
  set<int> s;

  for (int i = 1; i <= n; ++i) {
    s.insert(i);
  }

  for (auto n : v) {
    s.erase(n);
  }

  return *s.begin();
}

int sumApproach(const vector<int> v) {
  // * T:O(n) S:O(1)
  // * we don't do sum at once to prevent overflow
  // * some risk of overflow still exists
  int sum = v.size() + 1;
  for (int i = 0; i < v.size(); ++i) {
    sum += i + 1 - v[i];
  }
  return sum;
}

int xorApproach(const vector<int> v) {
  // * T:O(n) S:O(1)
  int n = v.size() + 1;
  int a = 0, b = 0;
  for (int i = 1; i <= n; ++i) {
    a ^= i;
  }

  for (int n : v) {
    b ^= n;
  }
  return a ^ b;
}

void smokeTest() {
  for (int i = 0; i < 100; ++i) {
    cout << "test: " << i + 1 << endl;
    int n = randomNumber(1, 100);
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
      v[i] = i + 1;
    }

    random_shuffle(v.begin(), v.end());
    v.pop_back();

    printVector(v, "vector: ");
    int a = naiveApproach(v);
    int b = xorApproach(v);

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
  smokeTest();
  // cout << setApproach({1, 2, 3, 4}) << endl;
  return 0;
}
