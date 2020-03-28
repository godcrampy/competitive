#include <string>
#include <vector>

using namespace std;

// Backtracking Algorithm IMP https://www.youtube.com/watch?v=qBbZ3tS0McI

vector<string> generateParenthesis(int n) {
  vector<string> res;
  backtrack(res, "", 0, 0, n);
  return res;
}

void backtrack(vector<string> &res, string str, int open, int close, int max) {
  if (str.length() == 2 * max) {
    res.push_back(str);
    return;
  }

  if (open < max) backtrack(res, str + "(", open + 1, close, max);
  if (close < open) backtrack(res, str + ")", open, close + 1, max);
}