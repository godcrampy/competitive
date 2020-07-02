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

  puts("Vector after make_heap:");
  make_heap(v.begin(), v.end());

  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
