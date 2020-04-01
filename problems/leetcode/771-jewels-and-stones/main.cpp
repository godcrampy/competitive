#include <set>
using namespace std;

int numJewelsInStones(string J, string S) {
  set<char> s;
  for (char c : J) {
    s.insert(c);
  }
  int count = 0;
  for (char c : S) {
    if (s.find(c) != s.end()) {
      ++count;
    }
  }
  return count;
}