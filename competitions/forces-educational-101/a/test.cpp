#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

int randomNumber(int l, int r) {
  // * Returns a random integer from [l, r]
  return l + (std::rand() % (r - l + 1));
}

template <typename T>
void printVector(const vector<T> &v, string msg) {
  cout << msg;
  for (auto n : v) {
    cout << n << " ";
  }
  cout << endl;
}

bool solvable(int pos, string &s, int stk) {
  // deb(s);
  // deb2(pos, stk);
  if (stk < 0) {
    return false;
  }
  if (pos >= s.length()) {
    return stk == 0;
  }

  char next = s[pos];
  switch (next) {
    case '(':
      return solvable(pos + 1, s, stk + 1);
    case ')':
      return solvable(pos + 1, s, stk - 1);

    default:
      return solvable(pos + 1, s, stk + 1) || solvable(pos + 1, s, stk - 1);
      break;
  }
}

bool solve(string s) {
  ll s1 = 0, s2 = 0;
  char prev = '.';

  for (char c : s) {
    switch (c) {
      case '(':
        if (prev == ')') {
          if ((s1 + s2) % 2 != 0) {
            return 0;
          }
          s2 = 0;
        }
        if (prev == '.' && s2 % 2 != 0) return false;
        ++s1;
        break;
      case ')':
        if (prev == '.' && s2 % 2 != 0) return false;
        if (s1) {
          --s1;
        } else if (s2) {
          --s2;
        } else {
          return 0;
        }
        break;
      default:
        ++s2;
        break;
    }
    prev = '(';
  }

  if (s1) {
    return s2 >= s1 && (s2 - s1) % 2 == 0;
  } else {
    return s2 % 2 == 0;
  }
}

void smokeTest() {
  unordered_map<int, char> m = {{1, '('}, {2, ')'}, {3, '?'}};
  for (ll i = 1; i <= 1000; ++i) {
    deb(i);
    int n = randomNumber(1, 5);
    string s = "";
    while (n--) {
      s.push_back(m[randomNumber(1, 3)]);
    }
    deb(s);
    bool solveA = solve(s), solveB = solvable(0, s, 0);
    deb2(solveA, solveB);
    if (solveA != solveB) {
      cout << "Fails\n";
      return;
    }
  }

  cout << "Pass\n";
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(0));

  smokeTest();
  return 0;
}
