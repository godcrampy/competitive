#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
T minimum_of_five(T a, T b, T c, T d, T e) {
  return min(a, min(b, min(c, min(d, e))));
}

template <class T>
T maximum_of_five(T a, T b, T c, T d, T e) {
  return max(a, max(b, max(c, max(d, e))));
}

template <class T>
T operate(T a, char op, T b) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    default:
      cout << "Error: invalid operator" << endl;
  }
  return a;
}

long long maximum_value(string &expression) {
  int length = expression.length();
  int n = (length + 1) / 2;  // number of digits

  // 1 index array
  vector<int> numbers(n + 1, 0);
  vector<char> operations(n, '.');

  for (int i = 0; i < length; ++i)
    if (i % 2 == 0)
      // char at i is a digit
      numbers[i / 2 + 1] = expression[i] - '0';
    else
      // char at i is an operation
      operations[(i + 1) / 2] = expression[i];

  vector<vector<long long>> max_table(n + 1, vector<long long>(n + 1, 0));
  vector<vector<long long>> min_table(n + 1, vector<long long>(n + 1, 0));

  for (auto i = 1; i <= n; ++i) {
    max_table[i][i] = numbers[i];
    min_table[i][i] = numbers[i];
  }

  for (auto s = 1; s <= n - 1; ++s)
    for (auto i = 1; i <= n - s; ++i) {
      auto j = i + s;
      long long mini = __LONG_LONG_MAX__;
      long long maxi = -__LONG_LONG_MAX__ - 1;
      for (auto k = i; k <= j - 1; ++k) {
        long long m_l = min_table[i][k];
        long long M_l = max_table[i][k];
        long long m_r = min_table[k + 1][j];
        long long M_r = max_table[k + 1][j];
        char op = operations[k];
        mini = minimum_of_five(mini, operate(m_l, op, m_r), operate(m_l, op, M_r), operate(M_l, op, m_r), operate(M_l, op, M_r));
        maxi = maximum_of_five(maxi, operate(m_l, op, m_r), operate(m_l, op, M_r), operate(M_l, op, m_r), operate(M_l, op, M_r));
      }
      max_table[i][j] = maxi;
      min_table[i][j] = mini;
    }
  return max_table[1][n];
}

int main(int argc, char const *argv[]) {
  string input;
  cin >> input;
  cout << maximum_value(input) << endl;
  return 0;
}
