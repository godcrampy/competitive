#include <set>

using namespace std;

bool isHappy(int n) {
  set<int> s;
  while (true) {
    if (n == 1) return true;
    n = happify(n);
    if (s.find(n) != s.end()) {
      return false;
    }
    s.insert(n);
  }
}
int happify(int n) {
  int sum = 0;
  while (n > 0) {
    sum += (n % 10) * (n % 10);
    n /= 10;
  }
  return sum;
}