#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  set<long> alice3, alice2, alice1, bob;
  long input;
  for (int i = 0; i < n; ++i) {
    cin >> input;
    bob.insert(input);
    if (input % 3 == 0) {
      alice3.insert(input);
    } else if (input % 2 == 0) {
      alice2.insert(input);
    } else {
      alice1.insert(input);
    }
  }

  int aliceScore = 0, bobScore = 0, tie = 0;

  long a, b;
  while (!alice3.empty()) {
    a = *alice3.begin();
    b = *bob.begin();
    alice3.erase(a);
    bob.erase(b);
    if (a > b)
      ++aliceScore;
    else if (b > a)
      ++bobScore;
    else
      ++tie;
  }

  while (!alice2.empty()) {
    a = *alice2.begin();
    b = *bob.begin();
    alice2.erase(a);
    bob.erase(b);
    if (a > b)
      ++aliceScore;
    else if (b > a)
      ++bobScore;
    else
      ++tie;
  }

  while (!alice1.empty()) {
    a = *alice1.begin();
    b = *bob.begin();
    alice1.erase(a);
    bob.erase(b);
    if (a > b)
      ++aliceScore;
    else if (b > a)
      ++bobScore;
    else
      ++tie;
  }

  cout << aliceScore << " " << bobScore << " " << tie << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
