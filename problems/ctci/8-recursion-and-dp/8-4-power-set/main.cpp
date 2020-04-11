#include <iostream>
#include <set>

using namespace std;

set<set<int>> power_set(set<int> s) {
  // * Time: O(n*2^n)
  // * Space: O(n*2^n)
  if (s.size() == 0) {
    return {{}};
  }
  int a = *s.begin();
  s.erase(a);

  auto ps = power_set(s);
  for (auto new_set : ps) {
    new_set.insert(a);
    ps.insert(new_set);
  }

  return ps;
}

int main(int argc, char const *argv[]) {
  set<int> s = {1, 2, 3};

  auto ps = power_set(s);

  for (auto ss : ps) {
    for (auto e : ss) {
      cout << e << " ";
    }
    cout << endl;
  }
  return 0;
}
