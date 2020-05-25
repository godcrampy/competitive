#include <iostream>
#include <vector>

using namespace std;

void solve() {
  long long ones, twos, threes, fours;
  cin >> ones >> twos >> threes >> fours;
  long long count = 0;
  long long oneTwo = min(ones, twos);
  count += oneTwo;
  ones -= oneTwo;
  twos -= oneTwo;

  long long twoThreeFour = min(min(twos, threes), fours);
  count += twoThreeFour;
  cout << count << endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; ++_) {
    solve();
  }
  return 0;
}
