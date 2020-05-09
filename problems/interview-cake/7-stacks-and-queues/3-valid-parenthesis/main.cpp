#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(const string& code) {
  // determine if the input code is valid
  stack<char> s;

  for (char c : code) {
    if (c == '(' || c == '[' || c == '{') {
      s.push(c);
    }

    if (c == ')') {
      if (s.empty() || s.top() != '(') {
        return false;
      }
      s.pop();
    }

    if (c == ']') {
      if (s.empty() || s.top() != '[') {
        return false;
      }
      s.pop();
    }

    if (c == '}') {
      if (s.empty() || s.top() != '{') {
        return false;
      }
      s.pop();
    }
  }

  return s.empty();
}
