// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/balanced-brackets-3-4fc590c6/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_opening_bracket(char c) { return c == '{' || c == '(' || c == '['; }

bool are_pairs(char a, char b) {
  return (a == '[' && b == ']') || (a == '(' && b == ')') ||
         (a == '{' && b == '}');
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  getchar();

  for (int _ = 0; _ < t; ++_) {
    stack<char> s;
    string input;
    cin >> input;
    getchar();
    bool err = false;
    for (char c : input) {
      if (is_opening_bracket(c)) {
        s.push(c);
      } else {
        if (!s.empty() && are_pairs(s.top(), c)) {
          s.pop();
        } else {
          err = true;
          break;
        }
      }
    }
    if (!s.empty() || err) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
