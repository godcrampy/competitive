#include <stdlib.h>
#include <cmath>
#include <iostream>

using namespace std;

long position_to_range(long a) {
  return (sqrt(8 * (a - 1) + 1) - 1) / 2 + 1;
}

long range_to_starting_position(long a) {
  return a * (a - 1) / 2 + 1;
}

void log_fraction(long position) {
  auto range = position_to_range(position);
  auto first_of_range = range_to_starting_position(range);
  if (range % 2)
    cout << range - (position - first_of_range) << "/" << (position - first_of_range + 1) << endl;
  else
    cout << (position - first_of_range + 1) << "/" << range - (position - first_of_range) << endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  for (auto i = 0; i < t; ++i) {
    int a;
    cin >> a;
    cout << "TERM " << a << " IS ";
    log_fraction(a);
  }
  return 0;
}
