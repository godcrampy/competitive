#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

void solve() {
  int n;
  cin >> n;
  multiset<long> s;
  long temp;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    s.insert(temp);
  }
  // sort(s.begin(), s.end());

  long time = 0;
  long count = 0;
  while (!s.empty()) {
    // find smallest number that is greater or equal than time
    bool found = false;
    auto i = s.lower_bound(time);
    long val = *i;
    if (val >= time) {
      found = true;
      time += val;
      ++count;
      s.erase(i);
    }
    if (!found) {
      // remove first guy
      time += *s.begin();
      s.erase(s.begin());
    }
  }

  cout << count << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
