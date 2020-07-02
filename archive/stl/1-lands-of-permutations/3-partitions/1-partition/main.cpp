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

  puts("Vector after partition:");
  auto a = partition(v.begin(), v.end(), [](int a) { return a % 2 == 0; });
  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;
  auto b = partition_point(v.begin(), v.end(), [](int a) { return a % 2 == 0; });
  cout << *a << endl;
  cout << *b << endl;

  return 0;
}
