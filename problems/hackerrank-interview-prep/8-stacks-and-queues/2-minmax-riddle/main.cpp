#include <bits/stdc++.h>

using namespace std;

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
  int n = arr.size();
  // getNextMin
  stack<long> s;
  vector<long> nextMin(n, n);
  for (int i = 0; i < n; ++i) {
    if (s.empty()) {
      s.push(i);
      continue;
    }
    while (!s.empty() && arr[i] < arr[s.top()]) {
      nextMin[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }

  while (!s.empty()) s.pop();
  // getPrevMin
  vector<long> prevMin(n, -1);

  for (int i = n - 1; i >= 0; --i) {
    if (s.empty()) {
      s.push(i);
      continue;
    }
    while (!s.empty() && arr[i] < arr[s.top()]) {
      prevMin[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  // map n => largestWindow
  unordered_map<long, long> maxWindowSize;
  for (int i = 0; i < n; ++i) {
    maxWindowSize[arr[i]] =
        max(maxWindowSize[arr[i]], nextMin[i] - prevMin[i] - 1);
  }

  // reverse map
  unordered_map<long, long> windowToMaxMin;
  for (auto p : maxWindowSize) {
    windowToMaxMin[p.second] = max(windowToMaxMin[p.second], p.first);
  }
  vector<long> v;
  long prev = -1;
  for (int i = n; i >= 1; --i) {
    if (windowToMaxMin.find(i) != windowToMaxMin.end()) {
      v.push_back(max(windowToMaxMin[i], prev));
      prev = max(prev, windowToMaxMin[i]);
    } else {
      v.push_back(prev);
    }
  }

  reverse(v.begin(), v.end());
  // fill array
  return v;
}
