#include <bits/stdc++.h>

using namespace std;

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
  stack<int> stk;
  long maxArea = 0;
  int i = 0;

  while (i < h.size()) {
    if (stk.empty() || h[stk.top()] <= h[i]) {
      stk.push(i++);
    } else {
      int top = stk.top();
      stk.pop();
      if (stk.empty()) {
        maxArea = max(maxArea, (long)h[top] * i);
      } else {
        maxArea = max(maxArea, (long)h[top] * (i - stk.top() - 1));
      }
    }
  }

  while (!stk.empty()) {
    int top = stk.top();
    stk.pop();
    if (stk.empty()) {
      maxArea = max(maxArea, (long)h[top] * i);
    } else {
      maxArea = max(maxArea, (long)h[top] * (i - stk.top() - 1));
    }
  }

  return maxArea;
}
