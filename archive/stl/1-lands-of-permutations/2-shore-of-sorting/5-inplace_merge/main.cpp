#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> v = {4, 5, 7, 1, 2, 6, 8};
  puts("Vector:");
  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;

  puts("Vector after merge:");
  inplace_merge(v.begin(), v.begin() + 3, v.end());

  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
