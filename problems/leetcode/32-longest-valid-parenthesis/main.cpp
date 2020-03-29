#include <stack>
#include <string>
#include <vector>

using namespace std;

int longestValidParentheses(string s) {
  stack<int> stk;
  int length = 0;
  stk.push(-1);

  for (int i = 0; i < s.length(); ++i) {
    char c = s[i];
    if (c == '(') {
      stk.push(i);
    } else {
      stk.pop();

      if (stk.empty()) {
        stk.push(i);
      } else {
        length = max(length, i - stk.top());
      }
    }
  }
  return length;
}