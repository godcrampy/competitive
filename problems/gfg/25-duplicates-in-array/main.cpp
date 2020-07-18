#include <algorithm>
#include <iostream>
#include <vector>

// Given an array of n elements which contains elements from 0 to n-1,
// with any of these numbers appearing any number of times. 
// Find these repeating numbers in O(n) and using only constant memory space.
// https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/

using namespace std;

void getRepeatedSuper(vector<int> v) {
  int s = v.size();
  for(int i = 0; i < v.size(); ++i) {
    // new multiplied, old added => new divide, old mod
    int targetIndex = v[i] % s;
    v[targetIndex] = (v[targetIndex] / s + 1) * s + (v[targetIndex] % s);
  }

  for(int i = 0; i < v.size(); ++i) {
    cout << i << ": " << v[i] / s << endl;
  }
}

void solve() {
  int n;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  getRepeatedSuper(v);
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
