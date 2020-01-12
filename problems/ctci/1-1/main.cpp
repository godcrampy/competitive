#include <iostream>
#include <set>

using namespace std;

bool is_string_unique(string s) {
  set<char> store;
  for (auto a : s) {
    if (store.find(a) != store.end()) {
      // charecter already exists
      return false;
    }
    store.insert(a);
  }
  return true;
}

int main(int argc, char const *argv[]) {
  /* code */
  string s;
  cin >> s;
  cout << is_string_unique(s) << endl;
  return 0;
}
