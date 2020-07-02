#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> v = {5, 4, 7, 8, 1, 6, 2};
  puts("Vector:");
  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;

  puts("Vector after nth_element:");
  nth_element(v.begin(), v.begin() + 1, v.end());

  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
