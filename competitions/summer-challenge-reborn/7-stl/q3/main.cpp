#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  multiset<long, greater<long>> S;

  long input;
  for (int i = 0; i < n; ++i) {
    cin >> input;
    S.insert(input);
  }

  while (S.size() > 1) {
    long x = *S.begin();
    S.erase(S.begin());
    long y = *S.begin();
    S.erase(S.begin());

    if (x > y) {
      S.insert(x - y);
    }

    if (y > x) {
      S.insert(y - x);
    }

    for (auto n : S) {
      cout << n << " ";
    }
    cout << endl;
  }

  if (S.size())
    cout << *S.begin() << endl;
  else
    cout << -1 << endl;
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
